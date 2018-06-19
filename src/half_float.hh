/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*
 * Randall Woodall                                                      *
 * June 15, 2018                                                        *
 * half_float_store.hh                                                  *
 * Provides storage headers for a half-precision floating point number. *
 * Emphasis on storage optimization.                                    *
 * Follows IEEE-754-2008                                                *
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*
 */
#ifndef HALF_FLOAT
#define HALF_FLOAT
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
#endif