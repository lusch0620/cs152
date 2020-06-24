#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mastermind.h"

/* num_digits
 *   purpose: finds how many digits are in a number
 * inputs:
 *   unsigned int number - the inputted number
 * return value:
 *   unsigned into the number of digits in the number
 */
unsigned int num_digits(unsigned int number)
{
     int acc = 1;
	
	//iteratively loop through each digit of a number 
     while((number / 10) > 0)
     {
          acc++;
          number = number / 10;
     }
     return acc;
}

/* test_num_digits
 *   purpose: tests the num_digits function
 * inputs:
 *   unsigned int number - the inputted number
 *   unsigned int expected - the expected output
 * return value
 *   unsigned int - 1 for success, 0 for failure
 */
unsigned int test_num_digits(unsigned int number, unsigned int expected)
{
     int answer = num_digits(number);
	
	//if the answer is what is expected
     if(answer == expected)
     {
          printf("num_digits(%d) = %d Success\n", number, answer);
          return 1;
     }
	//if the answer is not what is expected
     else
     {
          printf("num_digits(%d) = %d Expected: %d FAILURE\n", number,
                 answer, expected);
          return 0;
     }
}

/* extract_digit
 *	purpose: decides what value is in the specified digit of a pattern
 * inputs:
 *	unsigned int pattern - the pattern being analyzed
 *	unsigned int digit - the digit being extracted
 * return value:
 *	unsigned int - the number at the specified digit of the pattern
 */
unsigned int extract_digit(unsigned int pattern, unsigned int digit)
{
	//if there are 0 digits in a given number
	if(digit == 0)
	{
		return(pattern % 10);
	}
	//extract the specified digit
	else
	{
		return(((int) (pattern / pow(10, digit))) % 10);
	}
}

/* test_extract_digit
 *	purpose: tests the extract_digit function
 * inputs:
 *	unsgined int pattern - the pattern being tested
 *	unsgined int digit - the digit being extracted
 *	unsgined int expected - the expected return value
 * return value:
 *	unsigned int - 1 for success, 0 for failure
 */
unsigned int test_extract_digit(unsigned int pattern, unsigned int digit,
	unsigned int expected)
{
	int answer = extract_digit(pattern, digit);

	//if the answer is what is expected
	if(answer == expected)
	{
		printf("extract_digit(%d,%d) = %d Sucess\n", pattern, digit,
			  answer);
		return 1;
	}
	//if the answer is not what is expected
	else
	{
		printf("extract_digit(%d,%d) = %d. Expected: %d FAILURE\n", pattern,
			  digit, answer, expected);                                                       
          return 0;  
	}
}

/* num_of_color
 *	purpose: decides how many instances of a color are in a pattern
 * inputs:
 *	unsigned int pattern - the pattern being analyzed
 *	unsigned int color - the number corresponding with a certain color
 * return value:
 *	unsigned int - the number of times a color shows up in a pattern
 */
unsigned int num_of_color(unsigned int pattern, unsigned int color)
{
	int i, matches = 0;

	//iteratively loop through the pattern to see how many colors there are
	for(i = 0; i < 4; i++)
	{
		if(extract_digit(pattern, i) == color)
		{
			matches++;
		}
	}
	return matches;
}

/* test_num_of_color
 * 	purpose: tests the num_of_color function
 * inputs:
 *   unsgined int pattern - the pattern being tested                            
 *   unsgined int digit - the digit being extracted                             
 *   unsgined int expected - the expected return value                          
 * return value:                                                                
 *   unsigned int - 1 for success, 0 for failure
 */
unsigned int test_num_of_color(unsigned int pattern, unsigned int digit,
	unsigned int expected)
{
	int answer = num_of_color(pattern, digit);

	//if the answer is what is expected
	if(answer == expected)
	{
		printf("num_of_color(%d,%d) = %d Success\n", pattern, digit,
			   answer);
		return 1;
	}
	//if the answer is not what is expected
	else
	{
		printf("num_of_color(%d,%d) = %d Expected: %d FAILURE\n", pattern,
			  digit, answer, expected);
		return 0;
	}
}

/* count_exact_matches
 *	purpose: counts how many digits in a guess match both in color and 
 *		    position as compared to the solution
 * inputs:
 *	unsigned int guess - the player's guess pattern
 * 	unsigned int solution - the solution pattern being compared to 
 * return value:
 *	unsigned int - the number of digits in the guess that matches both color
 *   			and position of the solution
 */
unsigned int count_exact_matches(unsigned int guess, unsigned int solution)
{
	int digit, acc = 0;
	
	//iteratively loop through each digit
	for(digit = 0; digit < 4; digit++)
	{
		//if the specific digit in guess and solution are the same
		if(extract_digit(guess, digit) == extract_digit(solution, digit))
		{
			acc++;
		}
	}

	return acc;
}

/* test_count_exact_matches
 * 	purpose: tests the count_exact_matches function
 * inputs:
 * 	unsigned int guess - the guess pattern
 *	unsigned int solution - the solution pattern
 *	unsigned int expected - the expected return value
 * return value:
 *	unsigned int - 1 for success, 0 for failure
 */
unsigned int test_count_exact_matches(unsigned int guess,
	unsigned int solution, unsigned int expected)
{
	int answer = count_exact_matches(guess, solution);

	//if the answer is what is expected
	if(answer == expected)
	{
		printf("count_exact_matches(%d,%d) = %d Success \n", guess, 
			  solution, answer);
		return 1;
	}
	//if the answer is not what is expected
	else
	{
		printf("count_exact_matches(%d,%d) = %d Expected: %d FAILURE\n",
			  guess, solution, answer, expected);
		return 0;
	}
}

/* colors
 *	purpose: prints out the colors in the pattern
 * inputs:
 * 	unsigned int guess - the player's guess pattern
 * return value:
 * 	unsigned int - the colors in the pattern
 */
unsigned int colors(unsigned int guess)
{
	unsigned int d1 = extract_digit(guess, 0), d2 = extract_digit(guess, 1);
	unsigned int d3 = extract_digit(guess, 2);
	unsigned int guess_holder = guess, holder;
	
	//if the first digit repeats itself in the pattern, take it out
	if(num_of_color(guess_holder, d1) > 1)
	{
		guess_holder = guess_holder / 10;
	}
	
	//if the second digit repeats itself in the pattern and the pattern is
	//currently 4 digits long
	if(num_of_color(guess_holder, d2) > 1 && num_digits(guess_holder) == 4)
	{
		holder = guess_holder % 10;
		guess_holder = ((guess_holder / 100) * 10) + holder;
	}
	//if the second digit repeats itself in the pattern and the pattern is
	//currently 3 digits long
	else if(num_of_color(guess_holder, d2) > 1 &&
		   num_digits(guess_holder) == 3)
	{
		guess_holder = guess_holder / 10;
	}
	//if the second digit never repeats itself
	else
	{
		guess_holder = guess_holder;
	}
	
	//if the third digit repeats itself in the pattern and the pattern is
	//currently 4 digits long
	if(num_of_color(guess_holder, d3) > 1 && num_digits(guess_holder) == 4)
	{
		holder = guess_holder % 100;
		guess_holder = (100 * (guess_holder / 1000)) + holder;
	}
	//if the third digit repeats itself in the pattern and the pattern is
	//currently 3 digits long
	else if(num_of_color(guess_holder, d3) > 1 &&
		   num_digits(guess_holder) == 3)
	{
		holder = guess_holder % 10;
		guess_holder = ((guess_holder / 100) * 10) + holder;
	}
	//if the third digit repeats itself in the pattern and the pattern is
	//currently 2 digits long
	else if(num_of_color(guess_holder, d3) > 1 &&
		   num_digits(guess_holder) == 2)
	{
		guess_holder = guess_holder / 10;
	}
	//if the third digit never repeats itself
	else
	{
		guess_holder = guess_holder;
	}

	return guess_holder;

}
/* test_colors
 *	purpose: tests the repeat function
 * inputs:
 * 	unsigned int guess - the player's guess pattern
 *	unsigned int expected - the expected result
 * return value:
 *	unsigned int - 1 for success, 0 for failure
 */
unsigned int test_colors(unsigned int guess, unsigned int expected)
{
	int answer = colors(guess);
	
	//if the answer is what is expected
	if(answer == expected)
	{
		printf("colors(%d) = %d Success\n", guess, answer);
		return 1;
	}
	//if the answer is not what is expected
	else
	{
		printf("colors(%d) = %d Expected: %d FAILURE\n", guess,
			  answer, expected);
		return 0;
	}
}
/* count_color_matches
 * 	purpose: counts how many digits in a guess pattern match in color,
 *		    disregarding position as compared to the solution
 * inputs:
 *	unsigned int guess: the player's guess pattern
 *	unsigned int solution - the solution pattern being comapred to
 * return value:
 *	unsigned int - the number of digits in a guess pattern that match the
 *				solution in color
 */
unsigned int count_color_matches(unsigned int guess, unsigned int solution)
{
	int guess_colors = colors(guess), sol_colors = colors(solution);
	int sol_digits = num_digits(sol_colors);
	int guess_digits = num_digits(guess_colors);
	int i, j, acc = 0;
	
	//iteratively loop through guesses and solutions as many times as there
	//are digits in the guess pattern
	for(i = 0; i < guess_digits; i++)
	{
		//iteratively loop through guesses and solutions as many times as
		//there are digits in the solution pattern
		for(j = 0; j < sol_digits; j++)
		{
			//if the guess pattern colors match with the solution pattern
			//colors
			if(extract_digit(guess_colors, i) ==
			   extract_digit(sol_colors, j))
			{
				acc++;
			}
		}
	}
	return acc;


}

/* test_count_color_matches
 *	purpose: tests the count_color_matches function
 * inputs:
 *	unsigned int guess - the player's guess pattern
 *	unsgined int solution - the solution pattern
 *	unsigned int expected - the expected return value
 * return value;
 *	unsigned int - 1 for success, 0 for failure
 */
unsigned int test_count_color_matches(unsigned int guess, 
	unsigned int solution, unsigned int expected)
{
	int answer = count_color_matches(guess, solution);
	
	//if the answer is what is expected
	if(answer == expected)
	{
		printf("count_color_matches(%d,%d) = %d Success \n", guess, solution,
			  answer);
		return 1;
	}
	//if the answer is not what is expected
	else
	{
		printf("count_color_matches(%d,%d) = %d Expected: %d FAILURE\n",
			  guess, solution, answer, expected);
		return 0;
	}
}

/* get_guess_feedback
 * 	purpose: makes sure that both the guess and solution adheres to the 
 *		    4-digit, values 1-6 format
 * inputs:
 * 	unsigned int guess - the player's guess pattern to be verified
 *	unsigned int solution - the solution pattern to be verified
 * return value:
 * 	unsigned int - a 2-digit number, the first being # of exact matches
 *			     and the second being # of additional color matches
 */
unsigned int get_guess_feedback(unsigned int guess, unsigned int solution)
{
	int em = count_exact_matches(guess, solution);
	int cm = count_color_matches(guess, solution);
	int d1 = extract_digit(guess, 0), d2 = extract_digit(guess, 1);
	int d3 = extract_digit(guess, 2), d4 = extract_digit(guess, 3);


	//makes sure that the guess and solution patterns are only 4 digits long
	//and that they only have colors 1-6
	if(num_digits(guess) == 4 && num_digits(solution) == 4 &&
	   d1 <= 6 && d1 >= 0 && d2 <= 6 && d2 >= 0 && d3 <= 6 && d3 >= 0 &&
	   d4 <= 6 && d4 >= 0)
	{
		//if the guess pattern has no exact matches and no color matches
		if(em == 0 && cm == 0)
		{
			return 0;
		}
		//if the guess pattern has more exact matches than color matches
		else if(em >= cm)
		{
			return (em * 10);
		}
		//if the guess pattern has 0 exact matches but at least 1 
		//color match
		else if(em == 0 && cm > 0)
		{
			return cm;
		}
		//if the guess pattern has more than one exact matches but 0 
		//color matches
		else if(em > 0 && cm == 0)
		{
			return em;
		}
		//if the guess pattern has at least one exact match and color
		//match - exact match is = 0
		else if(em > 0 && (cm - em) == 0)
		{
			return em;
		}
		//the normal case
		else
		{
			return ((em * 10) + (cm - em));
		}

	}
	//raise an error if the criteria don't match
	else
	{
		fprintf(stderr,"Invalid inputs, please make sure that the guess"
			  " pattern and solution pattern are both 4 digits long\n");
		return -1;
	}
	
}

/* test_get_guess_feedback
 *	purpose: tests the get_guess_feedback function
 * inputs:
 *	unsigned int guess - the guess pattern
 *	unsigned int solution - the solution pattern
 *	unsgined int expected - the expected answer
 * return value:
 * 	unsigned int - 1 for success, 0 for failure
 */
 unsigned int test_get_guess_feedback(unsigned int guess, 
 	unsigned int solution, unsigned int expected)
{
	int answer = get_guess_feedback(guess, solution);

	//if the answer is what is expected
	if(answer == expected)
	{
		printf("get_guess_feedback(%d,%d) = %d Success\n", guess, solution,
			  answer);
		return 1;
	}
	//if the answer is not what is expected
	else
	{
		printf("get_guess_feedback(%d,%d) = %d Expected: %d FAILURE\n", 
			  guess, solution, answer, expected);
		return 0;
	}
}

// TODO: Write a test function for each mstermind function

/* test_mastermind
 * This is the test function that has 3+ good test cases for this function in 
 * your mastermind program. This verifies that the bits are working so that if
 * you find a bug you can more easily localize it.
 * inputs:
 *   none. Tests are hard coded.
 * outputs:
 *   none. Test results are printed out.
 */
void test_mastermind()
{
	printf("MASTERMIND TESTS\n");

	printf("extract_digit tests:\n");
		test_extract_digit(1234, 0, 4);
		test_extract_digit(1234, 1, 3); 
		test_extract_digit(1234, 2, 2);
		test_extract_digit(1234, 3, 1);
		test_extract_digit(1234, 5, 0);
	printf("\nnum_of_color tests:\n");
		test_num_of_color(3413, 1, 1);
		test_num_of_color(1542, 4, 1);
		test_num_of_color(3413, 3, 2);
		test_num_of_color(2222, 2, 4);
		test_num_of_color(4231, 1, 1);
		test_num_of_color(3413, 2, 0);
	printf("\ncount_exact_matches tests:\n");
		test_count_exact_matches(3413, 2315, 1);
		test_count_exact_matches(1544, 2344, 2);
		test_count_exact_matches(3413, 2355, 0);
		test_count_exact_matches(5555, 5555, 4);
		test_count_exact_matches(3213, 3153, 2);
		test_count_exact_matches(2263, 2261, 3);
		test_count_exact_matches(3145, 2263, 0);
	printf("\ncolors tests:\n");
		test_colors(1234, 1234); 
		test_colors(2234, 234);
		test_colors(3413, 341);
		test_colors(2315, 2315);
	printf("\ncount_color_matches tests:\n");
		test_count_color_matches(3413, 2315, 2);
		test_count_color_matches(1234, 1234, 4);
		test_count_color_matches(2132, 4545, 0);
		test_count_color_matches(3212, 4313, 2);
		test_count_color_matches(2263, 2261, 2);
	printf("\nnum_digits tests:\n");
		test_num_digits(1234, 4);
		test_num_digits(1, 1);
		test_num_digits(123, 3);
	printf("\nget_guess_feedback tests\n");
		test_get_guess_feedback(3413, 2315, 11);
		test_get_guess_feedback(2263, 1245, 10); 
		test_get_guess_feedback(2263, 2261, 30);
		test_get_guess_feedback(3145, 2263, 1);
		test_get_guess_feedback(3413, 2263, 10);
}

/* print_mastermind_instructions
 * This prints out user instructions to play mastermind.
 * inputs:
 *   none
 * outputs:
 *   none. Insructions are printed to screen.
 */
void print_mastermind_instructions()
{
	printf("Welcome to mastermind. I am thinking of a 4-number\n");
	printf("sequence. All four numbers are between 1 and 6.\n");
	printf("You have 12 guesses to guess it correctly.\n");
	printf("Each time you guess, I'll tell two things.\n");
	printf("1. How many numbers are correct and in the correct position.\n");
	printf("2. How many other numbers are correct but in the wrong "
		  "position.\n");
	printf("Let's get started!!!\n");
}

/* get_new_code
 * Generates a 4-digit number, with each digit a number from 1 to 6, inclusive.
 * inputs:
 *   none
 * outputs:
 *   unsigned int - 4-digit number with each digit from 1 to 6
 */
unsigned int get_new_code()
{
	int i;
	int result = 0;
	for (i = 0; i < 4; i++)
	{
		result = result * 10;
		result = result + ((rand() % 6) + 1);
	}
	return result;
}


/* play_mastermind
 * This is the game loop to play mastermind. All print statements are provided 
 * so that you have consistent messages for grading purposes. An example of  
 * how to do error checking is provided so you can model that.
 * inputs:
 *  none. Users play interactively
 * outputs:
 *  none. Everything is printed.
 */
void play_mastermind()
{

	unsigned int guess_num = 0;
	unsigned int solution = 0;
	unsigned int guess = 0;
	unsigned int feedback = 0;
	print_mastermind_instructions();
	solution = get_new_code();
	int d1 = extract_digit(solution, 0), d2 = extract_digit(solution, 1);
	int d3 = extract_digit(solution, 2), d4 = extract_digit(solution, 3);
	// print this out so that we can tell whether yours matches ours.
	//don't remote.
	printf("solution: %u\n",solution);

	// Limit number of guesses to 12 guesses
	while(guess_num < 12)
	{
		//Prints out the guess number each time
		printf("Guess %d - ", (guess_num + 1));
		printf("Input your 4-digit guess: ");
		scanf("%u",&guess);

		//Call your functions to find out how close the guess was
		feedback = get_guess_feedback(guess, solution);;
		// report the feedback
		if(num_digits(feedback) == 2)
		{
			printf("Feedback: %u correct placement, correct color,\n",
				  feedback / 10);
			printf("%u incorrect placement, correct color\n",
				  feedback % 10);
		}
		else if(num_digits(guess) > 4 || d1 > 6 || d2 > 6 || d3 > 6 ||
			   d4 > 6)
		{
			printf("%u is an invalid guess. Make sure your guess is a "
			 	  "4-digit number, each digit between 1-6\n", 
				  guess);
			guess_num--;
		}
		else
		{
			printf("Feedback: 0 correct placement, correct color,\n");
			printf("%u incorrect placement, correct color\n", 
				  feedback);
		}
		
		// note: If it's an invalid guess, go back and ask the guess
		// immediately. Go back to Guess %d - . Don't print out the
		// Congratuations or Not quite below.
		if(num_digits(guess) > 4)
		{
			printf("%u is an invalid guess. Make sure your guess is a "
				  "4-digit number, each digit between 1-6.\n",
                	  guess);
			guess_num--;
		}

		// Detect whether guess was entirely correct:
		// if correct, print out congrats and return from this function.
		if(count_exact_matches(guess, solution) == 4)
		{
			printf("Congratulations! Your guess of %u was correct!\n",
				  guess);
			return;
		}
	// if incorrect, print out number of guesses left
	// if incorrect
		if(count_exact_matches(guess, solution) != 4)
		{
			printf("Not quite - you still have %u guesses left!\n",
				  12 - (guess_num + 1));
		}

		if(guess_num == 11)
		{
			printf("Sorry, you did not guess it! The solution was %u\n"
				   , solution);
		}
		guess_num++;
	}
}

