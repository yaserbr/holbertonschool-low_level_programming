# holbertonschool-low_level_programming
# Simple Calculator

## Description

A terminal-based calculator written in C. The program allows the user to perform basic arithmetic operations through a menu-driven interface.

## Compile

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 calculator.c -o calculator
```

## Run

```bash
./calculator
```

## Supported Operations

- Addition
- Subtraction
- Multiplication
- Division
- Quit the program

## Numeric Behavior

The calculator performs arithmetic using integer values entered by the user.

## Known Limitations

- User input is read using `scanf()`.
- Only integer menu options are validated.
- Menu choices must be within the valid range.
- Non-numeric input (such as letters or mixed characters) is not handled in the mandatory version.
- Division by zero is checked and prevented.
