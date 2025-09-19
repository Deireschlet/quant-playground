#include <iostream>
#include <vector>

#include "io.hpp"
#include "compute.hpp"

int main() {
    int path_length;
    float sigma;


    IO::readParameters(path_length, sigma);
    std::vector<float> random_walk = compute::discrete_random_walk(path_length, sigma);

    for(auto& step : random_walk){
        std::cout << step << '\n';
    }

    return 0;
}