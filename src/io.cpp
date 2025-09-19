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
}