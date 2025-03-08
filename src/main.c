#include <stdio.h>
#include <string.h>

#include "lib.h"

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
    if (v2 >= 0) {
        printf("\nYou need to add approximately %.2f mL of the %.2f mg/mL nicotine liquid.\n", v2, c2);
    }

    return 0;
}












