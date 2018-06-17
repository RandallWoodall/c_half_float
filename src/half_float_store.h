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

//A new type that declares the space required for half a float (16-bits)
typedef struct half_float {
    int * value;
} half_float;

void init(half_float to_init) {
    to_init.value = malloc(sizeof(int));
}

//Convert a given floating point number to half-float.
void set_value(int* value, int* to_convert_p) {
    int to_convert = *to_convert_p;
    printf("0x%032x\n", *value);
    //Clear value
    (*value) = 0x0000;
    //Pull the sign bit (from 32), and shift it to the MSB of new float
    (*value) = 0x8000 & (to_convert >> 16);
    printf("0x%032x\n", *value);
    //Pull the least significant 10 mantissa bits (12 through 22)
    //(*value) = (*value) | (0x03FF & (to_convert >> 13));
    //Pull the MSB from the exponent field
    //(*value) = (*value) | (0x7C00 & (to_convert >> 16));
}

//Convert a half_float to a float
float * get_value(int* value) {
    float * toRet = malloc(sizeof(int));
    printf("0x%032x", *value);
    (*toRet) = (0x80000000 & ((*value)<<16)) | (0x72F8F1FF);
    return toRet;
}
