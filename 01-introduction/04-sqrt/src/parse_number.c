#include <stdlib.h>
#include <math.h>
#include "sqrt.h"

/**
 * @brief Parses the number in the given string and stores the result as double
 * @param number The result will be stored here
 * @param str The string to parse
 * @retval 0 Number successfully parsed
 * @revatl -1 Failed to parse number
 */
int
parse_number(double *number, const char *str)
{
	char *end;
	*number = strtod(str, &end);
	
	if ((end == str) || (*end != '\0')){
		// str contained at least one "non-number" charecter
		return -1;
	}
	
	if (isnan(*number) || isinf(*number)){
		// The number is NaN (not a number) or infinite
		return -1;
	}
	
	// Success!
	return 0;
}
