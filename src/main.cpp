#include <iostream>
#include <vector>
#include <cmath>

#include "io.hpp"
#include "compute.hpp"

int main() {
    int path_length;
    float sigma;


    IO::readParameters(path_length, sigma);
    std::vector<float> random_walk = compute::discrete_random_walk(path_length, sigma);
    std::vector<float> wiener = compute::wienerProcess(1.0, path_length);

    if(IO::writeCsv(random_walk, "random_walk")){
        std::cout << "Csv file ready" << std::endl;
    }
    else{
        std::cout << "Something went wrong" << std::endl;
    }

    if(IO::writeCsv(wiener, "wiener_process")){
        std::cout << "Csv file ready" << std::endl;
    }
    else{
        std::cout << "Something went wrong" << std::endl;
    }



    return 0;
}