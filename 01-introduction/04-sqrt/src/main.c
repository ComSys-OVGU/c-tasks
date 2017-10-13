#include <stdio.h>
#include <stdlib.h>
#include "sqrt.h"

/**
 * @brief Prints the usage of this program
 * @param progname Name of this program to display in the usage message
 */
static void
print_usage(const char *progname)
{
	printf("Usage: %s <NUMBER> [PRECISION [GUESS]]\n", progname);
	puts(
		"\n"
		"NUMBER      = Number to calculate the square root of\n"
		"PRECISION   = The precision of the result (default: 0.00001)n"
		"GUESS       = The first guess for the square root (default: 1.0)"
	);
}

/**
 * @brief Entry point for the sqrt program. Calculates the square root of
 *        the number specified as command line argument.
 * @param argc Number of provided arguments + 1
 * @param argv Array of c string holding the command line arguments, in which
 *             argv[0] is the name of the program and argv[1] the first
 *             argument.
 */
int
main(int argc, const char **argv)
{
	double precision = 0.00001;
	double guess = 1.0;
	double number;
	
	// Parse arguments
	switch(argc){
	case 1:
	default:
		print_usage(argv[0]);
		return EXIT_FAILURE;
	case 4:
		if (parse_number(&guess, argv[3])){
			printf("\"%s\" is not a valid number!\n", argv[3]);
			return EXIT_FAILURE;
		}
		if (guess <= 0.0){
			puts("The guess has to be a positive number!");
			return EXIT_FAILURE;
		}
	case 3:
		if (parse_number(&precision, argv[2])){
			printf("\"%s\" is not a valid number!\n", argv[2]);
			return EXIT_FAILURE;
		}
		if ((precision <= 0.0) || (precision > 1.0)){
			puts("The precision has to be in the range (0.0; 1.0]");
			return EXIT_FAILURE;
		}
		
	case 2:
		if (parse_number(&number, argv[1])){
			printf("\"%s\" is not a valid number!\n", argv[1]);
			return EXIT_FAILURE;
		}
		if (number < 0.0){
			puts("This program calculates the square root of non-negative "
			     "numbers only.");
			return EXIT_FAILURE;
		}
	}
	
	print_result(number, heron_sqrt(number, precision, guess));
	return EXIT_SUCCESS;
}

