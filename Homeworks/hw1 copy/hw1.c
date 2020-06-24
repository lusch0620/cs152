/* Lucius Gao, luciusgao2001 */
/* CS 152, Winter 2020 */
/* Homework 1 */

#include <stdio.h>
#include <stdlib.h>

/* convert_length
 * purpose: convert length from centimeters to inches
 * inputs:
 *    double centimeters - the centimeters length to be converted into inches
 * return value:
 *    double - the same number converted to inches
 */
double convert_length(double centimeters)
{
	// TODO: Implement this function, remove fprintf
	//if the input is negative, return -1
	if (centimeters < 0.0)
	{
		fprintf(stderr,
			 "ERROR: convert_length recieved negative input\n");
  		return -1.0;
	}
  	//if all the conditions are met, go ahead and convert
  	else
  	{
	    	return (centimeters * 0.3937);
  	}
}

/* trapezoid_area
 * purpose: calculate the area of a trapezoid
 * inputs:
 *   unsigned int height - height of the trapezoid
 *   unsigned int base1 - length of base 1 of the trapezoid
 *   unsigned int base2 - length of base 2 of the trapezoid
 * return value:
 *   double - calculated area of the trapezoid
 */
double trapezoid_area(unsigned int height, unsigned int base1,
 unsigned int base2)
{
 	// TODO: Implement this function, remove fprintf
  	//do the calculation if all values are greater than 0
  	if(height > 0 && base1 > 0 && base2 > 0)
  	{
	    	return((base1 + base2) / 2) * height;
  	}
  	//returns 0 if a 0 is entered for any of the variables
  	else
  	{
		fprintf(stderr,
				"ERROR: trapezoid_area recieved 0 as an input\n");
  	  	return 0;
  	}

}

/* factorial
 *  purpose: calculates the factorial of a given number
 * inputs:
 *  unsigned int n: the number whose factorial needs to be calculated
 * return value:
 *  int - calculated factorial value
 */
int factorial(unsigned int n)
{
  	//base cases
  	if(n == 1 || n == 0)
  	{
    		return 1;
  	}
  	//general cases
  	else
  	{
  	  	return(n * (factorial(n-1)));
  	}
}

/* combination_solver
 *  purpose: solves the nCr formula
 * inputs:
 *  unsigned int row - the n value of nCr
 *  unsigned int column - the r value of nCr
 * return value:
 *  int - the answer to nCr
 */

 int combination_solver(unsigned int row, unsigned int column)
 {
   	return(factorial(row)) / 
		((factorial(column) * factorial(row - column)));
 }

/* print_number_triangle
 * 	purpose: print out the first 5 rows of a number triangle
 * inputs:
 *    unsigned int start_num
 * return value:
 *    none - output is printed to the screen
 * output
 *    print out the first 5 rows of a number triangle
 */
void print_number_triangle(unsigned int start_num)
{

 	// TODO: Implement this function, remove fprintf
 	int i, j, i_temp, row = 0, column = 0;

 	//ensures that no values will be over 3 digits
 	if(start_num <= 166)
 	{
   		//counter for rows
   		for(i = 0; i <= 4; i++)
   		{
			//counter for the number of tabs
     			for(j = 4; j > i; j--)
     			{
       				printf("\t");
     			}

			i_temp = i;

     		//loop for printing out the numbers in the triangle
	 		while(i_temp >= 0)
     			{
					printf("%3d",
					start_num * combination_solver(row, column));
       				printf("\t\t");
       				column++;
       				i_temp--;
     			}	
     		row++;
     		column = 0;
     		printf("\n");
   		}
 	}
	//error statements
	else
 	{
   		fprintf(stderr,"ERROR (print_number_triangle): ");
   		fprintf(stderr,"Numbers larger than 3 digits are not supported\n");
 	}
}

/***********************************************************
********** PLACE OTHER TEST FUNCTIONS HERE *****************
***********************************************************/

/* test_convert_length
 * 	purpose: tests the convert_length function
 * inputs:
 *    double centimeters - centimeters to convert
 *    double expected - expected result
 *    double wiggle_room - amount result can be wrong
 * outputs:
 *    unsigned int success - 0 for failure, 1 for success
 */
unsigned int test_convert_length(double centimeters, double expected,
 double wiggle_room)
{
 	double result = convert_length(centimeters);
 	//accounting for the wiggle room of the answer
	if ((result >= expected - wiggle_room) &&
     	(result <= expected + wiggle_room))
 	{
   		printf("convert_length(%f) = %f. Success\n",
     			centimeters, result);
   		return 1;
 	}
	// if it fails
 	else
 	{
  		printf("convert_length(%f) = %f. Expected %f. FAILURE\n",
     		centimeters, result, expected);
   		return 0;
 	}

}

/* test_trapezoid_area
 * purpose: his tests the trapezoid_area function
 * inputs:
 *  unsigned int height - height of the trapezoid
 *  unsigned int base1 - length of baes 1 of the trapezoid
 *  unsigned int base2 - length of base 2 of the trapezoid
 *  unsigned int expected - expected result
 * outputs:
 *  unsigned int success - 0 for failure, 1 for success
 */
unsigned int test_trapezoid_area(unsigned int height, unsigned int base1, 
 unsigned int base2, unsigned int expected)
{
	int f_answer = trapezoid_area(height, base1, base2);
	//if the answer is what was expected
  	if(f_answer == expected)
  	{
	    	printf("trapezoid_area(%d, %d, %d) = %d. ",
			 height, base1, base2, f_answer);
    		printf("Success\n");
    		return 1;
  	}
	//if the function is incorrect
 	else
  	{
    		printf("trapezoid_area(%d, %d, %d) = %d. ",
			 height, base1, base2, f_answer);
    		printf("Expected %d. FAILURE\n", expected);
    		return 0;
  	}
}

/* test_factorial
 *  purpose: this tests the factorial function
 * inputs:
 *  unsigned int n - to be calculated
 *  unsigned int expected - expected result
 * outputs:
 *  unsigned int success - 0 for failure, 1 for success
 */
unsigned int test_factorial(unsigned int n, unsigned int expected)
{
	int f_answer = factorial(n);
  	//if the function outputs the correct answer
	if(f_answer == expected)
  	{
    		printf("test_factorial(%d) = %d. ", n, f_answer);
    		printf("Success\n");
    		return 1;
  	}
	//if the function is incorrect
  	else
  	{
    		printf("test_factorial(%d) = %d ", n, f_answer);
    		printf("Expected %d. FAILURE\n", expected);
    		return 0;
  	}
}

/* test_combination_solver
 *  purpose: this tests the combination_solver function
 * inputs:
 *  unsigned int row: n of nCr
 *  unsigned int column: r of nCr
 *  unsigned int expected: expected output
 * outputs;
 *  unsigned int success - 0 for failure, 1 for success
 */
unsigned int test_combination_solver(unsigned int row, unsigned int column, 
unsigned int expected)
{
	int f_answer = combination_solver(row, column);
  	//if the function outputs the correct answer
	if(f_answer == expected)
  	{
    		printf("test_combination_solver(%d, %d) = %d. ", 
			row, column, f_answer);
    		printf("Success\n");
    		return 1;
  	}
	//if the function is incorrect
 	else
  	{
    		printf("test_combination_solver(%d, %d) = %d. ",
			 row, column, f_answer);
    		printf("Expected %d. FAILURE\n", expected);
    		return 0;
  	}
}

/* test_print_number_triangle
 *	 purpose: this tests the print_number_triangle function
 * input:
 *   unsigned int start_num - top of triangle
 * outputs:
 *   No return value. Prints info, calls function, returns.
 */
void test_print_number_triangle(unsigned int start_num)
{
	printf("number triangle: %d\n", start_num);
 	print_number_triangle(start_num);
 	printf("\n\n");
}

/***********************************************************
********** ONLY MAIN GOES BELOW THIS POINT *****************
***********************************************************/

int main()
{
  	printf("TESTS\n");
  	printf("\nconvert_length tests:\n\n");
  	test_convert_length(0, 0, 0.01);
  	test_convert_length(1, 0.3937, 0.01);
  	test_convert_length(100, 39.37, 0.01);
  	test_convert_length(-1, -1, 0.01);

  	printf("\ntrapezoid_area tests:\n\n");
  	test_trapezoid_area(0, 0, 1, 0);
  	test_trapezoid_area(5, 10, 14, 60);
  	test_trapezoid_area(3, 9, 7, 24);
	test_trapezoid_area(5, 7, 6, 123); 
  	printf("\nfactorial tests\n\n");
  	test_factorial(1, 1);
  	test_factorial(0, 1);
  	test_factorial(3, 6);
  	test_factorial(4, 24);

  	printf("\ncombination_solver tests\n\n");
  	test_combination_solver(1, 1, 1);
  	test_combination_solver(2, 1, 2);
  	test_combination_solver(4, 2, 6);
  	test_combination_solver(6, 2, 15);

  	printf("\nprint_number_triangle tests\n\n");
  	test_print_number_triangle(1);
  	test_print_number_triangle(4);
  	test_print_number_triangle(50);
  	test_print_number_triangle(166);
	test_print_number_triangle(200);
}

