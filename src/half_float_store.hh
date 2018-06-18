/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*
 * Randall Woodall                                                      *
 * June 15, 2018                                                        *
 * half_float_store.hh                                                   *
 * Provides storage methods for a half-precision floating point number. *
 * Emphasis on storage optimization.                                    *
 * Follows IEEE-754-2008                                                *
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*
 */

#include <stdlib.h>

//A new type that declares the space required for half a float (16-bits)
//(Utilizes a short.)
class half_float {
    private:
        short * value;
    public:
        half_float();
        half_float(float to_convert);
        void set_value(float to_convert);
        float get_value();
};

//Initialize the value to a memory address for short.
half_float::half_float() {
    value = (short*)malloc(sizeof(short));
}

//Value added constructor taking a value.
half_float::half_float(float to_convert) {
    value = (short*)malloc(sizeof(short));
    set_value(to_convert);
}

//Convert a given floating point number to half-float.
void half_float::set_value(float to_convert_f) {
    //value = (short*)malloc(sizeof(short));
    int to_convert = *(int *)&to_convert_f;
    //Get the sign, exponent, and mantissa
    int exponent;
    //Clear value
    (*value) = 0x0000;
    //Pull the sign bit (from 32), and shift it to the MSB of new float
    (*value) = 0x8000 & (to_convert >> 16);
    //Pull the most significant 10 mantissa bits (12 through 22)
    (*value) = (*value) | (0x03FF & (to_convert >> 13));
    //Pull the exponent field, normalize and set up for half precision
    exponent = 0x00FF & (to_convert >> 23);
    exponent = exponent - 127;
    if(exponent > 30)
        (*value) = 0x7FE0;
    else {
        exponent = exponent + 15;
    }
    //Put in the exponent
    (*value) = (*value) | (exponent << 10);
}

//Convert a half_float to a float
float half_float::get_value() {
    int * toRet = (int*)malloc(sizeof(int));
    int exponent = ((*value) & 0x7C00) >> 10;
    exponent = exponent - 15 + 127;
    (*toRet) =((0x8000 & (*value)) << 16) | (exponent << 23) | ((0x03FF & (*value)) << 13);
    return *(float*)toRet;
}
