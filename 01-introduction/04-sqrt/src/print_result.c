#include <stdio.h>
#include <stdlib.h>
#include "sqrt.h"

/**
 * @brief Print the sqrt result to the terminal
 * @param square The number to the sqrt was calculated of
 * @param root The sqrt of `square`
 */
void
print_result(double square, double root)
{
	double actual_square = root*root;
	double diff = actual_square - square;
	if (diff < 0.0)
		diff = -diff;
	
	printf(
		"The square root of %f is approximatly %f.\n"
		"(%f * %f = %f, which is off by %f)\n",
		square, root, root, root, actual_square, diff
	);
}

