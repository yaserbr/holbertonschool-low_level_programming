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
