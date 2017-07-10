#include <stdio.h>
#include <stdlib.h>
#include "../unit_test.h"

void
critical_fail(void)
{
	puts("Critical test failed, ABORTING. Results so far:");
	test_results();
	exit(EXIT_FAILURE);
}

