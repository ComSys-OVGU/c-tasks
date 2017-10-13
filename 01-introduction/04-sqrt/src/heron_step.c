#include "sqrt.h"

/**
 * @brief Calculates the next estimation of the square root using the 
 *        Babylonian method
 * @param number The number to calculate the square root of
 * @param guess The current guess for the square root
 * @return The next guess for the square root
 */
double
heron_step(double number, double guess)
{
	// Basic idea of Babylonian method:
	// n = Number to get the squre root of
	// a = current guess (positive number)
	// b = Divide n by a
	// c = Average of a and b
	//
	// Case a) a is square root of n
	//     ==> b is also square root of n
	//     ==> c is also sqaure root of n
	// Case b) a is greater than the square root of n
	//     ==> b is less than the square root of n
	//     ==> c is a better guess than a and b
	// Case c) a is less than the square root of n
	//     ==> b is greater than the square root of n
	//     ==> c is a better guess than a and b
	//
	// Summing up: If the guess a is "correct", the next guess c is also
	// correct. If the guess a is "incorrect", the next guess c is a better
	// guess. Repeating this step will improve the estimation of the square
	// root with each iteration
}

