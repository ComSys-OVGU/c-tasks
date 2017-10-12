# Hello World!
## Motivation
When learning to code, you have to start at some point. This usually is the
"Hello World!" program.

## Task
- You'll find the file `hello.c` in this folder. Read it carefully
- Try to explain every single line of the file.
- Let's assume your favourite compiler is `gcc`:
	- Run `gcc -E hello.c`. This will show you the output of the preprocessor
		- What happend to `EXIT_SUCCESS`?
		- Can you find the forward declaration of the function `puts`?
	- Run `gcc -c -o hello.o -std=c99 -O0 -g -Wall -Wextra -Werror -pedantic hello.c`
		- This will invoke the preprocessor and compile to generate the machine
		  code for `hello.c`
		- `-c` tells GCC to compile, but not to link
		- `-o hello.o` tells GCC to store the comiled output as `hello.o`
		- `-std=c99` informs GCC that the source code follows the C99 standard
		- `-Wall -Wextra -pedantic` tells GCC to inform you about any problems
		  in your code. (Don't fool yourself by thinking a warning is only a
		  minor problem! A warning indicates a serious flaw in your code!)
		- `-Werror` tells GCC to treat warnings as errors. This should always
		  be enabled
		- `-g` is used to generate debug symbols. This is very usefull when
		  using debug tools like GDB or Valgrind.
		- `-O0` tells GCC to not optimize your code. This makes debugging much
		  easier. Use `-O3` or `-Os` in production code instead
	- Run `gcc -o hello hello.o`
		- This will invoke the linker. It will link in all required dependencies
		  from the standard C library and create the final executable `hello`
		- Run `./hello` to start the executable
		- Some programs depend on additional libraries. These have to be
		  specified using the `-l` option. E.g. to link against `libofat` and
		  `libxml` you have to specify `-lowfat -lxml` (the leading lib is
		  droppend).
