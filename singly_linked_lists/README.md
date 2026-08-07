# Singly Linked Lists

This project covers the fundamentals of singly linked lists in C.

## Learning Objectives

- Understand when and why to use linked lists instead of arrays
- Build and use linked lists
- Traverse a singly linked list
- Print elements of a linked list
- Count nodes in a linked list
- Manage dynamically allocated memory

## Data Structure

```c
typedef struct list_s
{
    char *str;
    unsigned int len;
    struct list_s *next;
} list_t;