# Binary Tree Task
## Motivation
Your task is to implement a database to store student records.
Each records consists of the students name and her enrollment number.
Retrieval of a single student data record identified by her enrollment number should have a complexity of $`\mathcal{O}(\log(n))`$.
Additionally, efficient access to groups of students identified by a range of enrollment numbers sorted by enrollment number needs to be implemented.

## Task
 - You have decided that a binary tree is the ideal data structure for your task
 - Implement the functions specified in [src/tree.h](src/tree.h):
   - Create for each function a separate file in `src`, for examples `src/search_student.c`
   - Hint: The functions are documented using Doxygen annotations
 - A `Makefile` is already provided, thus, you only need to type `make` to compile your code
 - By default, `make` will compile your binary tree implementation and unit tests and run the unit tests
 - Your implementation must pass all unit tests

## Hint
 - To iterate is human, to [recurse](https://en.wikipedia.org/wiki/Recursion_%28computer_science%29#Recursive_procedures), divine!
