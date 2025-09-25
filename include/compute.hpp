#include <iostream>
#include <vector>

namespace compute
{
    std::vector<float> discrete_random_walk(const int &path_length, const float &sigma);
    std::vector<float> wienerProcess(const float &horizon, const int &step_size);
}