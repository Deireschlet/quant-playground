#include <fstream>
#include <iostream>
#include <io.hpp>
#include <stdexcept>


using std::cout;
using std::cin;


namespace IO {
    void readParameters(int &path_length, float &sigma){

        cout << "Length of path: " << '\n';
        cin >> path_length;
        cout << "Sigma: " << '\n';
        while(cin >> sigma){
            if (sigma < 0){
                cout << "Only positive values allowed\n"; 
                continue;
            }
            else {
                break;
            }
        }
    }

    void writeCsv(const std::vector<float>& values, const std::string& filename) {
        std::string file_location = "data/" + filename + ".csv";
        std::ofstream file(file_location);  
        
        if (!file.is_open()) {
            throw std::runtime_error("Could not open file: " + file_location); 
        }

        file << "Index,Value\n";
        for (std::size_t i = 0; i < values.size(); ++i) {
            file << i << "," << values[i] << "\n";
        }
        std::cout << file_location << " created\n"; 
    }
}