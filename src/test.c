#include <stdio.h>
#include "half_float_store.h"

int main(void) {
    half_float testing;
    //init(testing);
    float testingAgain = -.05;
    set_value(testing.value, testingAgain);
    printf("%f", *get_value(testing.value));
}
