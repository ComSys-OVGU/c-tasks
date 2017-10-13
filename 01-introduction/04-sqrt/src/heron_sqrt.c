#include "sqrt.h"

/**
 * @brief Calculates the square root of the given number using the
 *        Babylonian method
 * @param number Number to calculate the square root of
 * @param precision The "degree of correctness" of the result
 * @param guess The first guess for the square root to begin with
 */
double
heron_sqrt(double number, double precision, double guess)
{
	// 1: Check if guess*guess is equal to number (with given precision)
	//    if equal --> return guess
	// 2: Update guess using Babylonian method
	// 3: Repeat
}

