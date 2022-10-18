#include "mcc_generated_files/mcc.h"
/* Overview: function can zoom any 8 x 8 bitmap by 1, 2,3 or 4 times.
 * This function reads a byte of hex data (character representation within an 8 element array), 
 * and replicates each pixel which is set to four pixels, and then stored in one of for arrays as follows:
 *  original pixel      zoomed pixel
 *      *                   *   *
 *                          *   *
 * Input: hex byte from character array
 * 
 *   col 0-7
    --------
   |    |lsb|
   |    |   |
   | 1  | 2 |       r   v
   |    |   |       o   a   i   h
   |--------|       w   l   n   e
   |    |   |           u       x
   |  3 | 4 |           e
   |    |   |
   |    |msb|
    --------
 * 
 * each 4 x 4 matrix is mapped to a larger 8 x 8 matrix, to allow for the increased size of the character
 * 
 * 
 * Output: 2 x pixel replication (vertically and horizontally)contained within four arrays of eight elements each
 * mapped each to 1,2,3,4 for the input array
 * 
 * 
 ******************************************************************************************************************
 pseudocode
 * repeat for 8 bytes of array1
 * read first hex byte from  character array1 to be displayed
 * check byte to see if there is a '1' contained within that byte
 * if a '1' is found
 * {
 * calculate the column and value of pixel A - pixel A = col + 1, pixel value <<1
 * calculate the column and value of pixel B - pixel B = col + 2, pixel value <<1
 * calculate the column and value of pixel C - pixel A = col + 1, pixel value <<1
 * calculate the column and value of pixel D - pixel A = col + 1, pixel value <<1
 */


void zoomChar(uint8_t  arr[8])
{
   
}
