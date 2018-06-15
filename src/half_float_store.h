/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*
 * Randall Woodall                                                      *
 * June 15, 2018                                                        *
 * half_float_store.h                                                   *
 * Provides storage methods for a half-precision floating point number. *
 * Emphasis on storage optimization.                                    *
 * Follows IEEE-754-2008                                                *
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*
 */

#include <stdlib.h>

//A new type that declares the space required for half a float (16-bits)
typedef struct half_float {
    char * value;
} half_float;

//Convert a given floating point number to half-float.
void set_value(char* value, int* to_convert_p) {
    int to_convert = *to_convert_p;
    //Clear value
    value = malloc(2);
    (*value) = 0x0000;
    //Pull the sign bit (from 32), and shift it to the MSB of new float
    (*value) = 0x8000 & (to_convert >> 16);
    //Pull the most significant 10 mantissa bits (12 through 22)
    (*value) = (*value) | (0x03FF & (to_convert >> 12));
    //Pull the LSB from the exponent field
    (*value) = (*value) | (0x7C00 & (to_convert >> 12));
}

//Convert a half_float to a float
float get_value(char* value) {
    return (float)(((0x8000 & (*value))<<16) | ((0x7C00 & (*value))<<12) | ((0x03FF & (*value))<<12));
}
