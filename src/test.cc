#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "half_float.hh"
#include "bfloat16.hh"

//Test the program by using a variable number of floats of each type
//(float, bfloat16 (intel), half_float (ieee 745 2008))

int main(int argc, char ** argv) {
    //Generate argv[0] float values, store them in a file
    srand(time(NULL));
    //std::ofstream file;
    //file.open("setup.dat");
    //for(int i = 0; i < std::stoi(argv[1]); i++)
    //    file << static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/5000)) << std::endl;
    //All values are in the file, time pulling and calculation with float
    half_float value = half_float(1.5743);
    std::cout << value.get_value() << std::endl;
}
