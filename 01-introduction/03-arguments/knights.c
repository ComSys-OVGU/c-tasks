#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(int argc, const char **argv)
{
	// argc = Number of arguments provided + 1
	// argv = Array of the arguments provided as string.
	// BUT: argv[0] = Name of the program, argv[1] = The first argument,
	//      argv[2] = The second argument, ...
	printf("The name of this program is %s\n", argv[0]);
	printf("This program was called with %i argument(s)\n", argc-1);
	
	if (argc >= 2){
		// At least one argument
		if (strcmp("secret", argv[1]) == 0){
			puts("The first argument was \"secret\"");
		} else {
			puts("The first argument was NOT \"secret\"");
		}
	}
	
	return EXIT_SUCCESS;
}

