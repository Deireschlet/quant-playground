#include <iostream>
#include <vector>
#include <random>
#include <cmath>

#include "compute.hpp"

namespace compute
{
    std::vector<float> discrete_random_walk(const int &path_length, const float &sigma){
        std::vector<float> path(path_length);
        std::random_device rd{};
        std::mt19937 gen{rd()};

        std::bernoulli_distribution dis(0.5);

        for(int i = 0; i < path_length - 1; ++i){
            if(dis(gen)){
                path[i + 1] = path[i] + sigma;
            }
            else{
                path[i + 1] = path[i] - sigma;
            }
        }

        return path;
    }

    std::vector<float> wienerProcess(const float &horizon, const int &path_length){
        std::vector<float> path(path_length + 1);
        std::random_device rd{};
        std::mt19937 gen{rd()};
        std::normal_distribution<float> standard_gaussian(0.0, 1.0);

        float dt = horizon / path_length;
        float sd = std::sqrt(dt); // factor is needed for the increment

        for(int i = 1; i <= path_length; ++i){
            float increment = standard_gaussian(gen) * sd; // make N(0,1) -> N(0, dt)
            path[i] = path[i - 1] + increment;
        }

        return path;

    }

    std::vector<float> GBM(const double &initial_value, const double &mu, const double &sigma, const int &path_length, const double &horizon){
        std::vector<float> path(path_length + 1);
        std::vector<float> wiener_path = wienerProcess(static_cast<float>(horizon), path_length);
        float dt = horizon / path_length;

        path[0] = initial_value;
        for(int i = 1; i <= path_length; ++i){
            float t = i * dt;
            path[i] = exp((mu - (sigma * sigma) * 0.5f) * t + sigma * wiener_path[i]); 
        }

        return path;
    }

    std::vector<float> jump_diffusion(
        const double &initial_value, 
        const double &mu, 
        const double &sigma, 
        const int &path_length, 
        const double &horizon,
        const double &lambda = 0.5){

        std::vector<float> path(path_length + 1);
        std::vector<float> wiener_path = wienerProcess(static_cast<float>(horizon), path_length);
        float dt = horizon / path_length;
        
        float mu_J = -0.10;
        float sigma_J = 0.04;

        std::random_device rd{};
        std::mt19937 gen{rd()};
        std::poisson_distribution<> jump(lambda * dt);
        std::normal_distribution<float> jump_size(mu_J, sigma_J);

        float kappa = exp(mu_J + 0.5 * sigma_J) - 1;

        path[0] = initial_value;
        for(int i = 1; i <= path_length; ++i){
            float t = i * dt;
            int jumps = jump(gen);
            double J = compute::jump_product(jumps, jump_size, gen);

            path[i] = exp((mu - lambda * kappa - (sigma * sigma) * 0.5f) * t + sigma * wiener_path[i]) * J; 
        }

        return path;
    }

}

