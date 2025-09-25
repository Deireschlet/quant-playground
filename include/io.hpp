#pragma once
#include <iostream>
#include <fstream>

namespace  IO {
    void readParameters(int &path_length, float &sigma);
    int writeCsv(const std::vector<float>& values, const std::string& filename);
}