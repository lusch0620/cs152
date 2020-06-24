/* Name: Lucius Gao
 * CNET: luciusgao2001
 * CS 152, Winter 2020
 * warmup3.h
 */
#ifndef WARMUP3_H
#define WARMUP3_H
#define NUM_ROWS 8
#define NUM_COLS 8

/* print_array                                                                  
 *   purpose: prints out a given array                                          
 * inputs:                                                                      
 *   int array[]: the inputted array                                            
 *   unsigned int length: the length of the inputted array                      
 * return value:                                                                
 *   no return value -- just prints out a given array                           
 */                                                                             
void print_array(int array[], unsigned int length);

/* remove_max
 *	purpose: finds the maximium item, removes all instances of that value from
 *		    the array , and returns the value
 * inputs:
 *	int array[]: the inputted array with values in it
 *	unsigned int length: the length of the array
 * return value:
 *	the max value found in the array / also note that the array changes
 */
int remove_max(int array[], unsigned int length);

/* init_board
 * initializes the contents of the checkerboard.
 * The blue pieces occupy rows 0 to (NUM_ROWS/2 - 2), and
 * the white pieces occupy rows (NUM_ROWS / 2 + 1) to NUM_ROWS-1
 * An 8x8 board looks like this:
   * b * b * b * b
   b * b * b * b *
   * b * b * b * b
   * * * * * * * *
   * * * * * * * *
   w * w * w * w *
   * w * w * w * w
   w * w * w * w *
 * inputs:
 *    char board[NUM_ROWS][NUM_COLS] - an NUM_ROWSxNUM_COLS board
 * outputs:
 *    none. prints the results.
 */
void init_board(char board[NUM_ROWS][NUM_COLS]);

/* is_empty
 *   purpose: decides if a selected cell in on the board is empty
 * inputs:
 *   char board[NUM_ROWS][NUM_COLS] - the current status of the board
 *   unsigned int row - the destination row value
 *   unsigned int col - the destination column value
 * return value:
 *   unsigned int - 1 if empty, 2 if not
 */
unsigned int is_empty(char board[NUM_ROWS][NUM_COLS], unsigned int row,
      unsigned int col);

/* place_piece                                                                  
 *   purpose: checks the validity of the destination location and places a      
 *            player's piece there                                              
 * inputs:                                                                      
 *   char board[NUM_ROWS][NUM_COLS]: the state of the current board             
 *   char player - denotes who the current player is                            
 *   unsigned int row - the destination row value                               
 *   unsigned int co - the destination column value                             
 * return value:                                                                
 *   unsigned int - 1 if a checker has been correctly added to the board        
 *                - 0 if the destination location is invalid                    
 */                                                                             
unsigned int place_piece(char board[NUM_ROWS][NUM_COLS], char player,           
     unsigned int row, unsigned int col);

/* print_board
 * prints the contents of the checkerboard.
 * The pieces are 'b', 'w', the kinged ones
 * are 'B'and 'W', and empty spaces are '*'
 * inputs:
 *    char board[NUM_ROWS][NUM_COLS] - an NUM_ROWSxNUM_COLS board
 * outputs:
 *    none. prints the results.
 */
void print_board( char board[NUM_ROWS][NUM_COLS]);

/* area_and_perimeter                                                           
 *   purpose: given the height and length, the area and height will be          
 *           calculated and returned                                            
 * input:                                                                       
 *   double height - the height of a given rectangle                            
 *   double length - the length of a given rectangle                            
 *   double *area - a pointer pointing to the address of the area that will     
 *                  be returned                                                 
 *   double *perimeter - a pointer pointing to the address of the perimeter     
 *                       that will be returned                                  
 * return value                                                                 
 *   changes the value of area and perimeter that was originally stored at the  
 *   address                                                                    
 */                                                                             
void area_and_perimeter(double height, double length, double *area,             
     double *perimeter);

/* remove_max_in_out
 *   purpose: removes the max value found in an array and also returns the
 *            current length of the array with the max(es) removed
 * input:
 *   int array[] - an array of a specified length
 *   unsigned int *length - a pointer pointing to the address of the variable
 *                          storing the length of the array
 * return value:
 *   the new updated length
 */
int remove_max_int_out(int array[], unsigned int *length);
#endif
