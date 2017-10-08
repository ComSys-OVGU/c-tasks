#include <stdbool.h>
#include <math.h>

#include "prime.h"

bool prime_singlethreaded(long long int p) {
	if(p==2 || p==3) 
		return true;
	if(p<2)
		return false;
	// numbers divisible by 2 or 3 are no primes
	if((p%6)!=1 && (p%6)!=5)
		return false;
	// loop through all numbers until an upper bound
	// hint: you may try to make this loop faster
	long long int upper_bound = (long long int) sqrt(p);
	for(int i=3; i<=upper_bound; i++)
		if(p%i==0) return false;
	return true;
}
