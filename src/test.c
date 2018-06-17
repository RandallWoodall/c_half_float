#include <stdio.h>
#include "half_float_store.h"

int main(void) {
    half_float testing;
    init(testing);
    float testingAgain = -.5;
    set_value(testing.value, (int*)&testingAgain);
    //printf("%f", *get_value(testing.value));
    get_value(testing.value);
}
