# Recursion

## Description
This project is a collection of C programs that solve various problems using **recursion** instead of loops. The goal is to practice recursive thinking and understand how a function can call itself to solve smaller instances of the same problem.

## Requirements
- Allowed editors: vi, vim, emacs
- Compiled on Ubuntu 20.04 LTS using `gcc`, with the following flags: `-Wall -Werror -Wextra -pedantic -std=gnu89`
- All files should end with a new line
- A `README.md` file is mandatory
- Code must follow the Betty coding style (checked with `betty-style.pl` and `betty-doc.pl`)
- No more than 5 functions per file
- The use of global variables is not allowed
- No more than one loop per function is allowed (and for most tasks, loops are not allowed at all — recursion only)
- You are allowed to use standard library functions
- In the following tasks, you're not allowed to use standard C library functions like `strchr`, `atoi`, `puts`... except `_putchar`
- You are not allowed to use these standard functions: `strtok`

## Files

| File | Description |
| --- | --- |
| `0-puts_recursion.c` | Prints a string, followed by a new line, using recursion |
| `_putchar.c` | Writes a single character to stdout |
| `main.h` | Header file containing all function prototypes |

## Usage

Each file is compiled and tested individually with its corresponding `main.c` file:

```bash
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c main.c 0-puts_recursion.c -o 0-puts_recursion
./0-puts_recursion
```

## Author
Julien