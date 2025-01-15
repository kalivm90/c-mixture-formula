#include <stdio.h>
#include <stdarg.h>
#include <string.h>

// Function to calculate v2
double calculate_v2(double c1, double v1, double c2, double cf);
// Function to gather necessary inputs
int get_valid_input(const char* prompt, const char *format, int expected_args, ...);

int main(int argc, char* argv[]) {

	double c1; // Current concentration in mg/mL
    double v1; // Current volume in mL
    double c2; // Concentration of liquid to add in mg/mL
    double cf; // Final desired concentration in mg/mL 
	
	// Get all input needed
	get_valid_input("\nWhat is the volume per ml and mg/ml of the base? (enter 2 numbers separated by a space): \n", "%lf %lf", 2, &v1, &c1);
    get_valid_input("Enter the concentration mg/ml of the added liquid? (enter one number): \n", "%lf", 1, &c2);
    get_valid_input("Enter the target concentration mg/mL (enter one number): ", "%lf", 1, &cf);
	
	double v2 = calculate_v2(c1, v1, c2, cf);
    if (v2 >= 0) 
	{
        printf("\nYou need to add approximately %.2f mL of the %.2f mg/mL nicotine liquid.\n", v2, c2);
    }

	/*
	char input[100]; // Used as a buffer for the first question
	char extra; // Used to make sure more than 2 questions arent entered
	
    while (1) 
	{
        // Prompt user for input
        printf("\nWhat is the volume per ml and mg/ml of the base? (enter 2 numbers separated by a space): \n");

        // Read the entire input line
        if (!fgets(input, sizeof(input), stdin)) 
		{
            // Handle unexpected input failure
            printf("Error reading input. Please try again.\n");
            continue;
        }
		
		if (sscanf(input, "%lf %lf %c", &v1, &c1, &extra) == 2) 
		{
            // Valid input: break out of the loop
            break;
        }
		
        // Invalid input: print an error message and reprompt
        printf("\nInvalid input. Please ensure you enter two numbers separated by a space.\n");
    }
	
	memset(input, '\0', sizeof(input));
	extra = '\0';
	
	while (1) 
	{	
		printf("Enter the concentration mg/ml of the added liquid? (enter one number): \n");
		
		if (!fgets(input, sizeof(input), stdin)) 
		{
			printf("Error reading input. Please try again.\n");
            continue;
		}

		if (sscanf(input, "%lf %c", &c2, &extra) == 1)
		{
			break;
		}

		printf("\nInvalid input. Please ensure you enter two numbers separated by a space.\n");
	}

	memset(input, '\0', sizeof(input));
    extra = '\0';

	while (1)
    {
        printf("Enter the target concentration mg/mL (enter one number): ");

        if (!fgets(input, sizeof(input), stdin))
        {
            printf("Error reading input. Please try again.\n");
            continue;
        }

        if (sscanf(input, "%lf %c", &cf, &extra) == 1)
        {
            break;
        }

        printf("\nInvalid input. Please ensure you enter two numbers separated by a space.\n");
    }
	
	double v2 = calculate_v2(c1, v1, c2, cf);
    if (v2 >= 0) {
        printf("\nYou need to add approximately %.2f mL of the 50 mg/mL nicotine liquid.\n", v2);
    }
	*/

/*	printf("What is the concentration in mg/ml of the added liquid? (enter one number): \n");
	scanf("%le", &c2);
	printf("Enter the target concentration mg/mL (enter one number): ");
    scanf("%lf", &cf);

	double v2 = calculate_v2(c1, v1, c2, cf);
	if (v2 >= 0) {
        printf("\nYou need to add approximately %.2f mL of the 50 mg/mL nicotine liquid.\n", v2);
    }
*/

    return 0;
}

double calculate_v2(double c1, double v1, double c2, double cf) {
    // Ensure the target concentration is achievable
    if (cf <= c1 || cf >= c2) {
        printf("Error: Target concentration must be between %.2f and %.2f mg/mL.\n", c1, c2);
        return -1; // Return -1 to indicate an error
    }
    // Using the rearranged formula to calculate v2
    return (cf * v1 - c1 * v1) / (c2 - cf);
}


int get_valid_input(const char* prompt, const char *format, int expected_args, ...) 
{
	char input [100];
	char extra;
	va_list args;
	int result;
	
	while (1) {
        // Display the prompt
        printf("%s", prompt);

        // Read the entire input line
        if (!fgets(input, sizeof(input), stdin)) {
            printf("Error reading input. Please try again.\n");
            continue;
        }
		
		printf("here\n");

        // Initialize the variadic argument list
        va_start(args, expected_args);
        result = vsscanf(input, format, args);
        va_end(args);
		
		printf("here 2 \n");

        // Check if the number of matched arguments is correct and there are no extra characters
        if (result == expected_args && sscanf(input, format, args) != EOF && strchr(input, '\n') != NULL) {
            break; // Valid input
        }
		
		printf("here 3 \n");

        printf("\nInvalid input. Please try again.\n");
    }
	
	return 1;
}











