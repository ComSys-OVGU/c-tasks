// Include header for standard input and output functions, such as
// printf (see man 3 printf), puts (see man 3 puts) or scanf (see man 3 scanf)
#include <stdio.h>

// Include header for standard functions and macros. Provides functions like
// exit (see man 3 exit) and macros like EXIT_SUCCESS or EXIT_FAILURE.
// It also provides functions like malloc (see man 3 malloc), but those are
// not interesting for now.
#include <stdlib.h>

int
main(void)
{
	puts("Hello world!");
	return EXIT_SUCCESS;
}

