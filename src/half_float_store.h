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
#include <stdio.h>
#include <math.h>

//A new type that declares the space required for half a float (16-bits)
typedef struct half_float {
    int value;
} half_float;

//Convert a given floating point number to half-float.
void set_value(int value, float to_convert_f) {
    int to_convert = *(int *)&to_convert_f;
    //Get the sign, exponent, and mantissa
    int exponent;
    //Clear value
    value = 0x0000;
    //Pull the sign bit (from 32), and shift it to the MSB of new float
    value = 0x8000 & (to_convert >> 16);
    //Pull the most significant 10 mantissa bits (12 through 22)
    value = value | (0x03FF & (to_convert >> 13));
    //Pull the exponent field, normalize and set up for half precision
    exponent = 0x00FF & (to_convert >> 23);
    exponent = exponent - 127;
    if(exponent > 30)
        value = 0x7FE0;
    else {
        exponent = exponent + 15;
    }
    //Put in the exponent
    value = value | (exponent << 10);
}

//Convert a half_float to a float
float * get_value(int value) {
    float * toRet = (float*)malloc(sizeof(int));
    (*toRet) =((0x8000 & value) << 16) | (0x72F8);
    return toRet;
}
