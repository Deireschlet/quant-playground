#pragma once
#include <iostream>
#include <vector>

namespace compute
{
    std::vector<float> discrete_random_walk(const int &path_length, const float &sigma);
    std::vector<float> wienerProcess(const float &horizon, const int &step_size);
    std::vector<float> GBM(const double &initial_value, const double &mu, const double &sigma, const int &path_length, const double &horizon);
    
    std::vector<float> jump_diffusion(
        const double &initial_value, 
        const double &mu, 
        const double &sigma, 
        const int &path_length, 
        const double &horizon,
        const double &lambda);
    
    template <typename Dist, typename Gen>
    double jump_product(int jumps, Dist& jump_dist, Gen& gen) {
        double result = 1.0;
        for (int k = 0; k < jumps; ++k) {
            result *= exp(jump_dist(gen));  
        }
        return result;
    }

}