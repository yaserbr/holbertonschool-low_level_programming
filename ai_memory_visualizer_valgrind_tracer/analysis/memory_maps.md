# Memory Maps and Corrected Reasoning

This document contains step-by-step memory maps for each example program and a critical review of AI-generated reasoning. The goal is explicit, concrete analysis of stack vs heap behavior, pointer aliasing, object lifetime, and the exact cause of each bug.

## 1. `stack_example.c`

### Program behavior
- `main()` calls `walk_stack(0, 3)`.
- `walk_stack()` sets a local `marker`, calls `dump_frame("enter", depth)`, optionally recurses, then calls `dump_frame("exit", depth)`.
- The program prints stack addresses for local variables at each depth.

### Key memory state points
1. `main()` frame is created.
2. `walk_stack(0, 3)` creates frame depth 0.
3. `walk_stack(1, 3)` creates frame depth 1.
4. `walk_stack(2, 3)` creates frame depth 2.
5. `walk_stack(3, 3)` creates frame depth 3.
6. The recursion unwinds back through depths 3, 2, 1, 0.

### Memory map

Stack frames grow downward in this run. Each function call allocates a fresh frame containing:
- `marker` in `walk_stack()`
- `local_int`, `local_buf`, and `p_local` in `dump_frame()`

Example frame layout for `depth=2`:
- `walk_stack()` frame at higher addresses than `depth=3` frame.
- `marker` at `0x0061FE9C` with value `20`.
- `dump_frame()` frame within `walk_stack()` call at `0x0061FE68` for `local_int`.
- `local_buf` at `0x0061FE58`.
- `p_local` holds `0x0061FE68`, the address of `local_int`.

### Explicit lifetime and aliasing
- `local_int` and `local_buf` are local to `dump_frame()` and exist only during that call.
- `p_local` is also local to `dump_frame()` and points into the same stack frame.
- When `dump_frame()` returns, `local_int`, `local_buf`, and `p_local` become invalid.
- Each `walk_stack()` recursion depth gets a different stack frame; same variable names at different depths are distinct objects.

### What AI often gets wrong here
AI can overstate the independence of variables without checking addresses. For example, it may say "each `local_buf` is a separate array and cannot overlap with others." That is true for this run, but it is only guaranteed because the compiler allocates a fresh stack frame per call. The real property is:
- Same variable names in recursive calls are different objects because each call has its own frame.
- The only reason they appear non-overlapping is because the stack pointer moved.

### Corrected explanation
The actual evidence from output proves the stack grows downward and that each recursion depth has its own local storage:
- `depth=0` `local_buf` at `0x0061FEB8`
- `depth=1` `local_buf` at `0x0061FE88`
- `depth=2` `local_buf` at `0x0061FE58`
- `depth=3` `local_buf` at `0x0061FE28`

This means the stack frame for each recursion level is separate and the frame for `depth=3` is still valid during the nested `dump_frame("exit", 3)` call.

## 2. `heap_example.c`

### Program behavior
- `main()` calls `person_new("Alice", 30)` and `person_new("Bob", 41)`.
- Each `person_new()` allocates a `Person` struct on the heap and a separate heap block for the copied name.
- `main()` frees `bob->name`, then `bob`, then only `alice` via `person_free_partial(alice)`.

### Memory map

Heap allocations:
- `alice` points to a `Person` block at `0x00DE1AC0`.
- `alice->name` points to a separate block at `0x00DE1AD0`.
- `bob` points to a `Person` block at `0x00DE1AE0`.
- `bob->name` points to a separate block at `0x00DE1AF0`.

Stack in `main()`:
- `Person *alice`
- `Person *bob`

Lifetime observations:
- `alice` and `bob` pointers are local to `main()` and live until `main()` returns.
- `alice->name` and `bob->name` live until they are freed explicitly.
- `free(bob->name)` deallocates the name string for `bob`.
- `free(bob)` deallocates the `bob` struct but does not affect `alice`.
- `person_free_partial(alice)` frees only the struct `alice`, not `alice->name`.

### Ownership analysis
- `alice` owns two heap objects: the `Person` struct and the name buffer.
- `bob` owns two heap objects as well.
- The code correctly frees `bob->name` and `bob`, so `bob` has no leak.
- The code fails to free `alice->name`; this is a memory leak.
- `person_free_partial()` is a partial destructor: it frees the outer object but not the owned inner string.

### Why this is wrong
A common AI oversight is saying "`person_free_partial(alice)` frees Alice completely." That is incorrect because the `Person` struct contains a pointer to separately-allocated memory. `free(alice)` only releases the bytes for the struct at `alice`; the heap block for `alice->name` remains allocated and unreachable after `alice` is freed.

### Corrected reasoning
Concrete ownership chain:
- `alice` → heap `Person` struct at `0x00DE1AC0`
- `alice->name` → heap buffer at `0x00DE1AD0`

After `person_free_partial(alice)`:
- `alice` becomes a dangling pointer.
- `alice->name` remains allocated and unreachable.
- This is a leak of exactly one heap object: the name string for Alice.

## 3. `aliasing_example.c`

### Program behavior
- `main()` calls `make_numbers(5)`.
- `make_numbers()` allocates an `int` array of 5 elements on the heap and initializes it.
- `main()` sets `b = a`, creating an alias.
- The program prints values through both pointers, then frees `a`.
- After the free, `b` is used to read and write the same memory.

### Memory map

Heap allocation:
- `a` and `b` alias the same heap block, for example at `0x00CC1AC0`.
- The block contains 5 `int` values: `0, 11, 22, 33, 44`.
- `a[2]` and `b[2]` both read the value `22` because they refer to the same memory.

Stack in `main()`:
- `int *a`
- `int *b`
- `int n = 5`

Stack in `make_numbers()`:
- `int i`
- `int *arr`

### Lifetime and aliasing
- `a` and `b` are aliases: they point to the same heap object.
- `free(a)` deallocates the heap block but does not change the pointer values stored in `a` or `b`.
- After `free(a)`, both `a` and `b` become dangling pointers.
- Any read or write through `b` after `free(a)` is undefined behavior.

### Detailed error chain
1. `a = make_numbers(n)` allocates heap memory and returns its address.
2. `b = a` makes `b` an alias of `a`; both point to the same heap block.
3. `free(a)` releases the heap block back to the allocator.
4. `printf("reading b[2]=%d\n", b[2])` dereferences a dangling pointer.
5. `b[3] = 1234` writes into freed memory, which can overwrite heap metadata or cause later corruption.

### Why AI explanation is incomplete or misleading
AI often says only "`b` is dangling after `free(a)`" and stops there. The critical detail is that aliasing means the exact same memory location is still being accessed through `b`.
- The value `22` may still print because the heap block has not yet been reused.
- That does not make the access valid.
- The memory is no longer owned by the program, so the read is undefined and the write is especially dangerous.

### Corrected interpretation
The program demonstrates two related issues:
- pointer aliasing (`a` and `b` share ownership of the same block before free), and
- use-after-free (`b[2]` and `b[3]` after `free(a)`).

A more precise phrasing is:
- `a` and `b` alias the same heap object;
- freeing via `a` invalidates the heap object for both pointers;
- using `b` afterward is invalid, regardless of whether the printed value matches the old contents.

## 4. `crash_example.c`

### Program behavior
- `main()` sets `n = 0` and calls `allocate_numbers(n)`.
- `allocate_numbers(0)` returns `NULL` because `n <= 0`.
- `main()` then dereferences `nums[0]`, causing a segmentation fault.

### Memory map

Stack in `main()`:
- `int *nums`
- `int n = 0`

Stack in `allocate_numbers()`:
- `int *arr`
- `int i`

Heap:
- No allocation occurs, because `n <= 0` causes an early return.

### Exact cause of the crash
- `nums` receives `NULL` from `allocate_numbers()`.
- `nums[0]` is equivalent to `*(nums + 0)`.
- Dereferencing `NULL` is a deterministic invalid access.
- The program faults immediately at `nums[0] = 42;`.

### Why a simple AI diagnosis may miss the full causal chain
A superficial explanation would say "the program dereferences NULL." That is correct but incomplete.
The full chain is:
1. `n` is set to `0`.
2. `allocate_numbers()` checks `if (n <= 0)` and returns `NULL`.
3. `main()` does not check the return value before using it.
4. `nums[0] = 42` dereferences `NULL` and crashes.

### Corrected explanation
This is not a heap bug; it is a control-flow and lifetime bug caused by relying on a function return without validating it.
- There is no allocated heap object for `nums`.
- `nums` is a `NULL` pointer, so the attempted write is a direct invalid access.
- The crash is deterministic and repeatable because the code always uses `n = 0`.

## Summary of AI correction examples

### Example 1: stack frame independence
- AI can assert that recursive locals are "safe because each call has its own variable." The missing detail is the stack frame lifetime: when a call returns, those locals die.
- Corrected: each `dump_frame()` call has its own `local_int` and `local_buf`, but they only exist during the call.

### Example 2: heap frees and partial destructors
- AI may say `free(alice)` releases Alice's memory completely.
- Corrected: `alice` owns two heap blocks, and only one is freed; the inner string remains leaked.

### Example 3: use-after-free aliasing
- AI may treat `b` as "dangling but still usable for observation." That is misleading.
- Corrected: `b` refers to the same freed heap block and any access is undefined.

### Example 4: crash cause chain
- AI may stop at "NULL dereference." The precise causal chain is `n == 0` → `allocate_numbers()` returns `NULL` → `nums[0]` dereference.

## Recommendations for accurate memory reasoning
- Always identify the storage class and lifetime: stack locals are temporary, heap allocations persist until `free()`.
- Track ownership explicitly: a pointer to a heap object does not imply ownership of nested allocations.
- Distinguish pointer value from validity: a non-NULL pointer can still be invalid after `free()`.
- Use actual runtime evidence when possible, especially addresses and return values.
