#include "fib.h"

uint32_t
fib_slow(uint32_t n)
{
	switch(n){
	case 0:
		return 0;
	case 1:
		return 1;
	default:
		return fib_slow(n-1) + fib_slow(n-2);
	}
}

