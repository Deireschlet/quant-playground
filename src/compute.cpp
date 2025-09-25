#include <iostream>
#include <vector>
#include <random>


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

    std::vector<float> wienerProcess(const float &horizon, const int &step_size){
        std::vector<float> path(step_size + 1);
        std::random_device rd{};
        std::mt19937 gen{rd()};
        std::normal_distribution<float> standard_gaussian(0.0, 1.0);

        float dt = horizon / step_size;
        float sd = std::sqrt(dt); // factor is needed for the increment

        for(int i = 1; i <= step_size; ++i){
            float increment = standard_gaussian(gen) * sd; // make N(0,1) -> N(0, dt)
            path[i] = path[i - 1] + increment;
        }

        return path;

    }
}

