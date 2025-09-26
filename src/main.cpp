#include <iostream>
#include <vector>
#include <cmath>

#include "io.hpp"
#include "compute.hpp"

int main() {
    int path_length{100000};
    float sigma{0.35};


    // IO::readParameters(path_length, sigma);
    std::vector<float> random_walk = compute::discrete_random_walk(path_length, sigma);
    std::vector<float> wiener = compute::wienerProcess(1.0, path_length);
    std::vector<float> gbm = compute::GBM(1, 0.05, 0.2, path_length, 1.0);
    std::vector<float> jump_diff = compute::jump_diffusion(1, 0.05, 0.2, path_length, 1.0, 0.5);

    try {
        IO::writeCsv(random_walk, "random_walk");
        IO::writeCsv(wiener, "wiener_process");
        IO::writeCsv(gbm, "gbm");
        IO::writeCsv(jump_diff, "jump_diff");
    }
    catch (const std::exception& e) {
        // Handles standard exceptions
        std::cerr << "Error: " << e.what() << '\n';
    }
    catch (...) {
        // Handles any other type of exception
        std::cerr << "Unknown error occurred\n";
    }


    return 0;
}