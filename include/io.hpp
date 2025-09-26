#pragma once
#include <iostream>
#include <fstream>

namespace  IO {
    void readParameters(int &path_length, float &sigma);
    void writeCsv(const std::vector<float>& values, const std::string& filename);
}