#include <fstream>
#include <iostream>
#include <io.hpp>


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

    int writeCsv(std::vector<float> const &values){
        std::ofstream file("data/output.csv");
        if (!file.is_open()) {
            return 0;
        }

        file << "Index,Value\n";
        for (std::size_t i = 0; i < values.size(); ++i) {
            file << i << "," << values[i] << "\n";
        }
        return 1;
    }
}