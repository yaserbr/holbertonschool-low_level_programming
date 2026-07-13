# Comparison Algorithms Metrics

Compile command:

```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 comparison_algorithms.c -o comparison_algorithms.exe
```

## Run 1

```text
Naive algorithm result: 625025000
Naive algorithm time: 1.227000 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000000 seconds
```

## Run 2

```text
Naive algorithm result: 625025000
Naive algorithm time: 1.167000 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000000 seconds
```

## Run 3

```text
Naive algorithm result: 625025000
Naive algorithm time: 1.178000 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000000 seconds
```

## Averages

Naive algorithm average time: 1.190667 seconds

Single-pass algorithm average time: 0.000000 seconds

## Relative Difference

Using the printed execution times, a finite times-slower ratio cannot be computed because the single-pass average time is 0.000000 seconds. The naive implementation averaged 1.190667 seconds slower in absolute measured time, while the single-pass implementation completed below the timer resolution in all three runs.
