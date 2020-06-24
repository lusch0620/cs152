/* Name: Lucius Gao
 * CNET: luciusgao2001
 * CS 152, Winter 2020
 * hw4_main.c
 */

#include <stdlib.h>
#include <stdio.h>
#include "hw4.h"
#include "hw4_provided.h"

int main()
{
	unsigned int ref_r[ROWS][COLS], ref_g[ROWS][COLS], ref_b[ROWS][COLS];   
	unsigned int res_r[ROWS][COLS], res_g[ROWS][COLS], res_b[ROWS][COLS];   
	unsigned int hid_r[ROWS][COLS], hid_g[ROWS][COLS], hid_b[ROWS][COLS];   
	unsigned int ref_image_width, ref_image_length;                            
	unsigned int hid_image_width, hid_image_length;

	provided_read_png("happyface.png", ref_r, ref_g, ref_b,                 
			&ref_image_width, &ref_image_length);   
	provided_read_png("uchicago.png", hid_r, hid_g, hid_b,                  
			&hid_image_width, &hid_image_length);   
	hide_image(ref_r, ref_g, ref_b, hid_r, hid_g, hid_b, res_r, res_g, 
			res_b, ref_image_width, ref_image_length);
	extract_image(res_r, res_g, res_b, hid_r, hid_g, hid_b, 
			hid_image_width, hid_image_length);
	encode("happyface.png", "uchicago.png", "uchicago_into_happyface.png"); 

	encode("uchicago.png", "happyface.png", "happyface_into_uchicago.png"); 

	// Tests to make sure that encode and decode both work correctly        
	decode("uchicago_into_happyface.png", "decoded1.png");                  

	decode("happyface_into_uchicago.png", "decoded2.png"); 

	test_hw4();
}
