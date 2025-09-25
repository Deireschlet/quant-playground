#pragma once
#include <iostream>
#include <fstream>

namespace  IO {
    void readParameters(int &path_length, float &sigma);
    int writeCsv(std::vector<float> const &values);
}