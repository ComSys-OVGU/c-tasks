#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "prime.h"
#include <unit_test.h>
#include <time.h>

const long long int some_primes[] = {
	2,3,5,7,11,13,17,
	10000000000000061, 10000000000000069, 10000000000000079, 10000000000000099, 
	10000000000000453, 10000000000000481, 10000000000000597, 10000000000000613,
	10000000000000639, 10000000000000669, 10000000000000753, 10000000000000793,
	10000000000000819, 10000000000000861, 10000000000000897, 10000000000000909,
	10000000000000931, 10000000000000949, 10000000000000957, 10000000000000991,
	10000000000001029, 10000000000001101, 10000000000001129, 10000000000001239,
	10000000000001293, 10000000000001311, 10000000000001321
};

const long long int some_non_primes[] = {
	4,6,8,9,10,12,14,15,16,18,
	10000000000000000, 10000000000000060, 10000000000000072, 10000000000000100, 
	10000000000000253, 10000000000000450, 10000000000000596, 10000000000000614,
	10000000000000649, 10000000000000659, 10000000000000763, 10000000000000783,
	10000000000000820, 10000000000000871, 10000000000000898, 10000000000000919,
	10000000000000941, 10000000000000950, 10000000000000953, 10000000000000981,
	10000000000001049, 10000000000001111, 10000000000001189, 10000000000001249,
	10000000000001295, 10000000000001322, 10000000000001323
};

void test_prime(bool prime(long long int p))
{
	int count;
	bool result;
	
	printf("some primes:\n");
	count = sizeof(some_primes)/sizeof(some_primes[0]);
	for (int i = 0; i < count; i++){
		printf("prime(%lld) = ", some_primes[i]);
		fflush(stdout);
		result = prime(some_primes[i]);
		printf("%d\n", result);
		TEST(result == true);
	}
	printf("some non-primes:\n");
	count = sizeof(some_non_primes)/sizeof(some_non_primes[0]);
	for (int i = 0; i < count; i++){
		printf("prime(%lld) = ", some_non_primes[i]);
		fflush(stdout);
		result = prime(some_non_primes[i]);
		printf("%d\n", result);
		TEST(result != true);
	}
}

int
main(void)
{
	time_t timer;
	double t_s,t_m;
	test_init();
	
	time(&timer);
	test_prime(prime_singlethreaded);
	t_s = difftime(time(NULL), timer);
	
	time(&timer);
	test_prime(prime_multithreaded);
	t_m = difftime(time(NULL), timer);
	
	test_results();
	
	printf("single-threaded version took %5.2fs\n", t_s);
	printf(" multi-threaded version took %5.2fs\n", t_m);
	
	return did_no_test_fail() ? EXIT_SUCCESS : EXIT_FAILURE;
}

