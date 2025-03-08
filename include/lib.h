#ifndef LIB_H
#define LIB_H

// Function to calculate v2
double calculate_v2(double c1, double v1, double c2, double cf);
// Function to gather necessary inputs
int get_valid_input(const char* prompt, const char *format, int expected_args, ...);

#endif
