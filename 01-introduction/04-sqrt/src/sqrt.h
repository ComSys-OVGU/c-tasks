#ifndef SQRT_H
#define SQRT_H
double heron_step(double number, double guess);
double heron_sqrt(double number, double precision, double guess);
int is_equal(double a, double b, double precision);
int parse_number(double *number, const char *str);
void print_result(double sqare, double root);
#endif
