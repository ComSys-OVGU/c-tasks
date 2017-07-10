#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include <stdint.h>

#define QUOTE(x) #x
#define TEST(x) test((x), QUOTE(x), __FILE__, __LINE__)

void critical_fail(void);
void test(int result, const char *expr, const char *file, uint32_t line);
void test_init(void);
void test_results(void);
int did_no_test_fail(void);

#endif

