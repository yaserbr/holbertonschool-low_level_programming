# Function Pointers

This directory contains C exercises about function pointers.

## Task 0 - What's my name

Write a function that prints a name.

Prototype:

```c
void print_name(char *name, void (*f)(char *));
```

The implementation file for this task is `0-print_name.c`.

## Task 1 - If you spend too much time thinking about a thing, you'll never get it done

Write a function that executes a function given as a parameter on each element
of an array.

Prototype:

```c
void array_iterator(int *array, size_t size, void (*action)(int));
```

The implementation file for this task is `1-array_iterator.c`.

## Task 2 - To hell with circumstances; I create opportunities

Write a function that searches for an integer.

Prototype:

```c
int int_index(int *array, int size, int (*cmp)(int));
```

The implementation file for this task is `2-int_index.c`.

## Task 3 - A goal is not always meant to be reached, it often serves simply as something to aim at

Write a program that performs simple operations.

Usage:

```sh
calc num1 operator num2
```

The files for this task are:

* `3-main.c`
* `3-op_functions.c`
* `3-get_op_func.c`
* `3-calc.h`

## Task 4 - Most hackers are young because young people tend to be adaptable

Write a program that prints the opcodes of its own main function.

Usage:

```sh
./main number_of_bytes
```

The implementation file for this task is `100-main_opcodes.c`.
