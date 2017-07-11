# Prime number

## Motivation
Sometimes you already [optimized](../fib) the fuck out of an algortihm, yet performance still sucks.
In these case, using more hardware is the only option left to further increase performance.
However, in the last years single core performance of CPUs made little progress.
Therefore, employing many processing cores is the only way to signaficantly increase processing power.

## Tasks
 - Write a parallized version of [src/prime_singlethreaded.c](src/prime_singlethreaded.c) in [src/prime_multithreaded.c](src/prime_multithreaded.c)
 - The number of threads used must be adjustable by changing the value of `NUM_THREADS`
 - Have a look at Amdahl's law and Gustafson's law
   - Why do both of them matter?
   - Which one better applies to matrix multiplication, which one better to the computation of a prefix sum?
