#include <math.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int age = 21;

    int* p;
    p = &age;
    printf("%p is the address\n", (void*)p);
    printf("%d is the value\n", age);

    *p = 30;

    printf("%d is the new value\n", age);
    printf("%d is also the new value\n", *p);

    return 0;
}
