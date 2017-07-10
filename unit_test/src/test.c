#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>
#include "../unit_test.h"
#include "globals.h"

void
test(int result, const char *expr, const char *file, uint32_t line)
{
	n_tests++;
	if (!result){
		n_fails++;
		printf("%s: FAILED (%s: %" PRIu32 ")\n", expr, file, line);
	}
#ifdef VERBOSE
	else 
	{
		printf("%s: ok\n", expr);
	}
#endif
}

