# Fibionacci number

## Motivation
Slow software requires faster hardware, more computation time and consumes more power.
Hence, bad performance in many cases costs big money.
In this task you must write an optimized version of the algorithm to calculate the Fibionacci number for the given index.
If you do your job good, your new version will perform better on your granddads [PDP-8](https://en.wikipedia.org/wiki/PDP-8) than the old version would on any modern CPU.

## Task
 - In [src/fib_slow.c](src/fib_slow.c) a working, but slow implementation of the algorithm is already given
 - Save your new implementation as `src/fib_fast.c`
 - Run `make` to compile your code and run unit tests
 - Your implementation must pass all unit tests

## Hints
 - Historically the Fibionacci sequence begins with 1 (1, 1, 2, 3, 5, ...), but here the modern version starting with 0 is meant (0, 1, 1, 2, 3, 5, ...)
 - A loop instead of a recursion will solve the performance problem, but a [tail recursion](https://stackoverflow.com/questions/33923/what-is-tail-recursion#37010) is much more elegant and just as fast
