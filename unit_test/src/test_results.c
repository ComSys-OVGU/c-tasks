#include <inttypes.h>
#include <stdio.h>
#include "../unit_test.h"
#include "globals.h"

void
test_results(void)
{
	puts("===============================================================\n");
	
	if (did_no_test_fail()){
		puts("All tests passed :-)\n");
	} else {
		printf("%" PRIu32 " out of %" PRIu32 " tests FAILED!\n",
		       n_fails, n_tests);
	}
}

