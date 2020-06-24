/* Name: Lucius Gao
 * CNET: luciusgao2001
 * CS 152, Winter 2020
 * checkers.h
 */
#ifndef CHECKERS_H
#define CHECKERS_H
#define NUM_ROWS 8
#define NUM_COLS 8
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


/* valid_white_normal_diagonal                                                  
 *   purpose: decides if a normal white piece made a valid move                 
 * inputs:                                                                      
 *   uint startrow - the origin row location                                    
 *   uint startcol - the origin column location                                 
 *   uint endrow - the destination row location                                 
 *   uint endcol - the destination column location                              
 *   char board[NUM_ROWS][NUM_COLS] - the current state of the board            
 * return values                                                                
 *   unsigned int - 2 for a valid diagonal jump                                 
                    1 for a valid single diagonal move                          
                    0 for invalid move                                          
 */                                                                             
unsigned int valid_white_normal_diagonal(unsigned int startrow,                 
     unsigned int startcol,unsigned int endrow, unsigned int endcol,            
     char board[NUM_ROWS][NUM_COLS]);     

/* valid_black_normal_diagonal
 *   purpose: decides if a black white piece made a valid move
 * inputs:
 *   uint startrow - the origin row location
 *   uint startcol - the origin column location
 *   uint endrow - the destination row location
 *   uint endcol - the destination column location
 *   char board[NUM_ROWS][NUM_COLS] - the current state of the board
 * return values
 *   unsigned int - 2 for a valid diagonal jump
                    1 for a valid single diagonal move
                    0 for invalid move
 */
unsigned int valid_black_normal_diagonal(unsigned int startrow,
     unsigned int startcol, unsigned int endrow, unsigned int endcol,
     char board[NUM_ROWS][NUM_COLS]);

/* valid_white_king_diagonal                                                    
 *   purpose: decides if a king white piece made a valid move                   
 * inputs:                                                                      
 *   uint startrow - the origin row location                                    
 *   uint startcol - the origin column location                                 
 *   uint endrow - the destination row location                                 
 *   uint endcol - the destination column location                              
 *   char board[NUM_ROWS][NUM_COLS] - the current state of the board            
 * return values                                                                
 *   unsigned int - 2 for a valid diagonal jump                                 
                    1 for a valid single diagonal move                          
                    0 for invalid move                                          
 */                                                                             
unsigned int valid_white_king_diagonal(unsigned int startrow, unsigned int startcol,
     unsigned int endrow, unsigned int endcol, char board[NUM_ROWS][NUM_COLS]);
/* valid_black_king_diagonal                                                    
 *   purpose: decides if a king white piece made a valid move                   
 * inputs:                                                                      
 *   uint startrow - the origin row location                                    
 *   uint startcol - the origin column location                                 
 *   uint endrow - the destination row location                                 
 *   uint endcol - the destination column location                              
 *   char board[NUM_ROWS][NUM_COLS] - the current state of the board            
 * return values                                                                
 *   unsigned int - 2 for a valid diagonal jump                                 
                    1 for a valid single diagonal move                          
                    0 for invalid move                                          
 */                                                                             
unsigned int valid_black_king_diagonal(unsigned int startrow,                   
     unsigned int startcol, unsigned int endrow, unsigned int endcol,           
     char board[NUM_ROWS][NUM_COLS]);         

/* valid_diagonal                                                               
 *   purpose: decides if the destination location is a valid move from the      
 *            origin location                                                   
 * inputs:                                                                      
 *   char player - denotes the player who is making the move                    
 *   uint startrow - the origin row location of the piece                       
 *   uint startcol - the origin column location of the piece                    
 *   uint endrow - the destination row location of the piece                    
 *   uint endcol - the destination column locatin of the piece                  
 *   char board[NUM_ROWS][NUM_COLS] - the current state of the board            
 * return values:                                                               
 *   unsigned int - 2 if valid jump move, 1 if valid single diagonal move,      
 *                  0 if not                                                    
*/   

unsigned int valid_diagonal(char piece, unsigned int startrow, 
	unsigned int startcol, unsigned int endrow, unsigned int endcol,
	char board[NUM_ROWS][NUM_COLS]);

/* available_move                                                               
 *   purpose: decides if a given piece has a valid move available               
 * inputs:                                                                      
 *   char player - denotes the player who is making the move                    
 *   uint startrow - the origin row location of the piece                       
 *   uint startcol - the origin column location of the piece                    
 *   char board[NUM_ROWS][NUM_COLS] - the current state of the board            
 * return value:                                                                
 *   unsigned int - 1 if there are moves available, 0 if no moves available     
 */ 
unsigned int available_move(char player, unsigned int startrow,
	unsigned int startcol, char board[NUM_ROWS][NUM_COLS]);

/* player_won
 *   purpose: checks if the player inputted has won
 * inputs:
 *   char board[NUM_ROWS][NUM_COLS]: the current state of the board
 *   char player - the player who might have won
 * return value:
 *   int - 1 if the player has won, else 0
 */
int player_won(char board[NUM_ROWS][NUM_COLS], char player);
/* replace                                                                      
 *   purpose: replaces switches the chars at the destination and origin         
 * inputs:                                                                      
 *   uint startrow - the origin row location of the piece                       
 *   uint startcol - the origin column location of the piece                    
 *   uint endrow - the destination row location of the piece                    
 *   uint endcol - the destination column location of the piece                 
 *   char board[NUM_ROWS][NUM_COLS] - the current state of the board            
 * return values:                                                               
 *   nothing returned, the array/board is just changed                          
 */   
void replace(unsigned int startrow, unsigned int startcol, unsigned int endrow, 
	unsigned int endcol, char board[NUM_ROWS][NUM_COLS]);

/* jump
 *   purpose: makes a jump move and reflects it in the array
 * inputs:
 *   uint startrow - the origin row location of the piece
 *   uint startcol - the origin column location of the piece
 *   uint endrow - the destination row location of the piece
 *   uint endcol - the destination column location of the piece
 *   char board[NUM_ROWS][NUM_COLS] - the current state of the board
 * return values:
 *   nothing returned, the array/board is changed
 */
void jump(unsigned int startrow, unsigned int startcol, unsigned int endrow,
     unsigned int endcol, char board[NUM_ROWS][NUM_COLS]);

/* do_move                                                                      
 *   purpose: checks that all the parameters are valid, and proceeds with       
 *            completing the move                                               
 * inputs:                                                                      
 *   char player - the current player making the move                           
 *   uint startrow - the origin row location of the piece                          
 *   uint startcol - the origin column location of the piece                       
 *   uint endrow - the destination row location of the piece                       
 *   uint endcol - the destination column location of the piece                    
 *   char board[NUM_ROWS][NUM_COLS] - the current state of the board            
 * return value:                                                                
 *   unsigned int- 2 for a jump, 1 for a normal move, 0 for invalid move        
 */ 	
unsigned int do_move(char player, unsigned int startrow, unsigned int startcol,
	unsigned int endrow, unsigned int endcol, char board[NUM_ROWS][NUM_COLS]);

/* computer_move
 *   purpose: computer finds the first valid move and makes it
 * input:
 *   char board[NUM_ROWS][NUM_COLS]: the current state of the board
 *   char player: the player the computer is playing as
 *   uint pointer row - a pointer to the row
 *   uint pointer col - a pointer to the column
 * return value:
 *   returns 1 if the computer made a move and 0 if it didn't make a move
 */
int computer_move(char board[NUM_ROWS][NUM_COLS], char player,
     unsigned int *row, unsigned int *col);

/* test_checkers
 *	purpose: 1 function to run all the test functions
 * inputs:
 * 	none
 * return value
 *	prints the results of the tests to the screen
 */
void test_checkers();

void play_checkers();
#endif
