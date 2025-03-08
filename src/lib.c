#include <stdarg.h>
#include <stdio.h>

double calculate_v2(double c1, double v1, double c2, double cf) {
    // Ensure the target concentration is achievable
    if (cf <= c1 || cf >= c2) {
        printf("Error: Target concentration must be between %.2f and %.2f mg/mL.\n", c1, c2);
        return -1; // Return -1 to indicate an error
    }
    // Using the rearranged formula to calculate v2
    return (cf * v1 - c1 * v1) / (c2 - cf);
}


int get_valid_input(const char* prompt, const char *format, int expected_args, ...) {
	char input [100];
	va_list args;
	int result;
	
    // While input is incorrect 
	while (1) {
        // Display the prompt
        printf("%s", prompt);

        // Read the entire input line
        if (!fgets(input, sizeof(input), stdin)) {
            printf("Error reading input. Please try again.\n");
            continue;
        }   

        // Initialize variable argument list
        va_start(args, expected_args);

        // Parse input using vsscanf
        result = vsscanf(input, format, args);

        // clean up
        va_end(args);

        // va_list can only be traversed once and result already traversed it.
        va_list args_copy;
        va_copy(args_copy, args);

        // printf("Debugging output: ");
        // for (int i = 0; i < expected_args; i++) 
        // {
        //     printf("%lf ", *va_arg(args_copy, double*));
        // }
        // printf("\n");
        // va_end(args_copy);

        if (result == expected_args) {
            break;
        } else {
            printf("Invalid input. Please enter the correct format.\n");
            printf("DEBUG, result: %d, expected_args: %d \n", result, expected_args);
        }
    }
	
	return 1;
}