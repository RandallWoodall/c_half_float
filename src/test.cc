#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "half_float.hh"
#include "bfloat16.hh"

//Test the program by using a variable number of floats of each type
//(float, bfloat16 (intel), half_float (ieee 745))

int main(int argc, char ** argv) {
    //Generate argv[0] float values, store them in a file
    srand(time(NULL));
    float * setup = (float*)malloc(sizeof(float) * std::stoi(argv[1]));
    std::ofstream file;
    file.open("setup.dat");
    for(int i = 0; i < std::stoi(argv[1]); i++)
        file << setup[i] << std::endl;
}
