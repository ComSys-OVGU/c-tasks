#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fib.h"
#include <unit_test.h>

static const uint32_t fibs[] = {
	0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597,
	2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418,
	317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465,
	14930352, 24157817, 39088169, 63245986, 102334155, 165580141, 267914296,
//	433494437, 701408733, 1134903170
};

static void
test_fib(uint32_t fib(uint32_t n))
{
	static const uint32_t count = sizeof(fibs)/sizeof(fibs[0]);
	uint32_t result;
	
	for (uint32_t i = 0; i < count; i++){
		printf("fib(%u) = ", i);
		fflush(stdout);
		result = fib(i);
		printf("%u\n", result);
		TEST(result == fibs[i]);
	}
}

int
main(void)
{
	test_init();
	
	test_fib(fib_slow);
	test_fib(fib_fast);
	
	test_results();
	
	return did_no_test_fail() ? EXIT_SUCCESS : EXIT_FAILURE;
}

