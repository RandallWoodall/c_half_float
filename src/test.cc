#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "half_float.hh"
#include "bfloat16.hh"

//Test the program by using a variable number of floats of each type
//(float, bfloat16 (intel), half_float (ieee 745 2008))

int main(int argc, char ** argv) {
    //Generate argv[1] float values, store them in a file
    srand(time(NULL));
    std::ofstream file;
    file.open("setup.dat");
    for(int i = 0; i < std::stoi(argv[1]); i++)
        file << static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/5000)) << std::endl;
    file.close();
    std::ifstream file2;
    file2.open("setup.dat");
    //All values are in the file, time pulling with float, double, half_float
    float * floats = (float*) malloc(sizeof(float) * std::stoi(argv[1]));
    double * doubles = (double*) malloc(sizeof(double) * std::stoi(argv[1]));
    half_float * halfs = (half_float*) malloc(sizeof(half_float) * std::stoi(argv[1]));
    for(int i = 0; i < std::stoi(argv[1]); i++) {
        std::string get;
        getline(file2, get);
        floats[i] = std::stof(get);
        doubles[i] = std::stod(get);
        halfs[i] = half_float(std::stod(get));
        std::cout << floats[i] << " " << doubles[i] << " " << halfs[i].get_value() << std::endl;
    }
}