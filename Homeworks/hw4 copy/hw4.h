/* Name: Lucius Gao
 * CNET: luciusgao2001
 * CS 152, Winter 2020
 * hw4.h
 */

#ifndef HW4_H
#define HW4_H
#define ROWS 50
#define COLS 50

/* hide_image                                                                   
 *   purpose: encodes an image inside of another image using their array of     
 *            pixels                                                            
 * inputs:                                                                      
 *   uint ref_r[ROWS][COLS]: reference image's array of red values              
 *   uint ref_g[ROWS][COLS]: reference image's array of green values            
 *   uint ref_b[ROWS][COLS]: reference image's array of blue values             
 *   uint hid_r[ROWS][COLS]: hidden image's arrray of red values                
 *   uint hid_g[ROWS][COLS]: hidden image's array of blue values                
 *   uint hid_b[ROWS][COLS]: hidden image's array of green values               
 *   uint res_r[ROWS][COLS]: resulting image's array of red values              
 *   uint res_g[ROWS][COLS]: resulting image's array of green values            
 *   uint res_b[ROWS][COLS]: resulting image's array of blue values             
 *   uint height: the height of the image                                       
 *   uint width: the width of the image                                         
 * return values:                                                               
 *   all of the resulting arrays                                                
 */ 
void hide_image(unsigned int ref_r[ROWS][COLS], unsigned int ref_g[ROWS][COLS],
	unsigned int ref_b[ROWS][COLS], unsigned int hid_r[ROWS][COLS], 
	unsigned int hid_g[ROWS][COLS], unsigned int hid_b[ROWS][COLS],
	unsigned int res_r[ROWS][COLS], unsigned int res_g[ROWS][COLS],
	unsigned int res_b[ROWS][COLS], unsigned int height, 
	unsigned int width);

/* extract_image
 *   purpose: decode an image and extract the hidden image
 * inputs:
 *   uint res_r[ROWS][COLS]: resulting image's array of red values
 *   uint res_g[ROWS][COLS]: resulting image's array of green values
 *   uint res_b[ROWS][COLS]: resulting image's array of blue values
 *   uint hid_r[ROWS][COLS]: hidden image's arrray of red values
 *   uint hid_g[ROWS][COLS]: hidden image's array of blue values
 *   uint hid_b[ROWS][COLS]: hidden image's array of green values
 * return values:
 *   none, changes the hidden arrays
 */
void extract_image(unsigned int res_r[ROWS][COLS],
     unsigned int res_g[ROWS][COLS], unsigned int res_b[ROWS][COLS],
     unsigned int hid_r[ROWS][COLS], unsigned int hid_g[ROWS][COLS],
     unsigned int hid_b[ROWS][COLS], unsigned int height,
     unsigned int width);

/* encode                                                                       
 *   purpose; encode an image into a another image                              
 * inputs:                                                                      
 *   char *ref_filename: the reference picture to hide the image into           
 *   char *hid_filename: the picture to be hidden into the reference picture    
 *   char *enc_filename: the resulting encoded image                            
 * return value:                                                                
 *   none, just creates a new encoded png file                                  
 */                                                                             
void encode(char *ref_filename, char *hid_filename, char *enc_filename);

/* decode
 *   purpose: decode a given image to reveal the hidden image
 * inputs:
 *   char *enc_filename: the image with a hidden image inside of it
 *   char *hid_filename: the decoded hidden image
 * return value:
 *   none, just creates a new file of the decoded hidden image
 */
void decode(char *enc_filename, char *hid_filename);

/* test_hw4
 *   purpose: tests all the functions written in hw4
 * inputs:
 *   none
 * retrn values:
 *   none
 */
void test_hw4();

#endif
