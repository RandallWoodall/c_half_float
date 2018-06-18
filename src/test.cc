#include <iostream>
#include "half_float_store.hh"

int main(void) {
    half_float testing;
    half_float test2(15.30912);
    float testingAgain = -20.05;
    testing.set_value(testingAgain);
    std::cout << testing.get_value() << std::endl << test2.get_value() << std::endl;
}
