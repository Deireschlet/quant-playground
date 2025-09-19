#include <iostream>
#include <vector>

namespace compute
{
    std::vector<float> discrete_random_walk(const int &path_length, const float &sigma){
        std::vector<float> path(path_length);

        for(int i = 0; i < path_length - 1; ++i){
            if(((double) rand() / (RAND_MAX)) <= 0.5){
                path[i + 1] = path[i] + sigma;
            }
            else{
                path[i + 1] = path[i] - sigma;
            }
        }

        return path;
    }
}

