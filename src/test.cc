#include <stdio.h>
#include "half_float_store.hh"

int main(void) {
    half_float testing;
    //init(testing);
    float testingAgain = -20.05;
    testing.value = (short*)malloc(sizeof(short));
    //init(testing);
    set_value(testing.value, testingAgain);
    printf("%f\n", *get_value(testing.value));
}
