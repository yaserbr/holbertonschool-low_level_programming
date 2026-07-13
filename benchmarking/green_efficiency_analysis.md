# Green Efficiency Analysis

## Measurement Methodology

I measured the programs by compiling and running the provided C files in the `benchmarking` directory, then using the printed execution times as the evidence for this report. For the baseline loop program, I recorded three runs of the same deterministic loop. The measured times were `0.240000`, `0.248000`, and `0.244000` seconds for `100000000` iterations. The average of those three runs is `0.244000` seconds.

For the algorithm comparison program, I also used three recorded runs. The naive implementation took `1.227000`, `1.167000`, and `1.178000` seconds, giving an average of `1.190667` seconds. The single-pass implementation printed `0.000000` seconds in all three runs, so its recorded average is also `0.000000` seconds.

Both implementations in the comparison program used the same fixed array size of `50000` integers. This keeps the comparison focused on the work done by each algorithm instead of changes in input data. The naive version repeatedly scans earlier parts of the array, while the single-pass version checks each element once.

## Observed Performance Differences

The baseline loop showed only a small amount of timing variation. Its fastest run was `0.240000` seconds and its slowest run was `0.248000` seconds, so the spread was `0.008000` seconds. That shows some normal measurement noise even though the computation itself was deterministic.

The comparison program showed a much larger difference. The naive algorithm averaged `1.190667` seconds, while the single-pass algorithm printed `0.000000` seconds every time. The single-pass result should not be read as literally taking no time. It means the measured time was too small to appear as a non-zero value with the timing method and printed output used here.

Because the single-pass average is printed as `0.000000`, I cannot calculate a meaningful finite "times slower" ratio between the naive algorithm and the single-pass algorithm from these recorded numbers. Dividing by zero would not be a valid comparison. What the output does show clearly is that the naive implementation took more than one second in every run, while the single-pass implementation finished below the visible measurement resolution in every run.

## Relation Between Runtime and Energy Consumption

This experiment measured runtime, not direct energy use. I did not record watts, joules, battery drain, CPU frequency, or temperature. Because of that, the results cannot prove an exact energy consumption difference between the two implementations.

Runtime still matters for energy because a program that keeps the CPU active longer gives the machine more time to spend energy on that work. In the recorded comparison, the naive algorithm averaged `1.190667` seconds on the same dataset where the single-pass algorithm printed `0.000000` seconds. Based on the measurements, the naive version clearly required more active execution time. If the machine's power use during both pieces of work were similar, the longer-running naive version would be expected to consume more energy, but this experiment did not measure that directly.

## Limitations of the Experiment

One major limitation is the resolution of the timing method. The single-pass algorithm printed `0.000000` seconds in all three runs, but that does not mean it used zero time. It means the measurement could not show a non-zero duration within the precision and visibility limits of the method used. Although `%.6f` prints six decimal places, the actual resolution of `clock()` can still depend on the environment.

Another limitation is the small number of runs. The baseline loop varied between `0.240000` and `0.248000` seconds, so timing noise is present. More runs would give a stronger average. The experiment also compared runtime only, not direct energy use, so the energy conclusion has to stay limited.

## Practical Engineering Takeaway

The main takeaway is that avoiding unnecessary repeated work can matter more than small timing variation. The baseline loop changed by only `0.008000` seconds across its recorded runs, but the naive algorithm averaged `1.190667` seconds while the single-pass version stayed below visible timing resolution. For green software engineering, the practical lesson is simple: choosing an algorithm that scans the data once can greatly reduce runtime compared with one that repeatedly revisits the same data. In this experiment, lower runtime is the strongest evidence available for better efficiency.
