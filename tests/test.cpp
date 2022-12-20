#include "..\lib\operations.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg) {
        cout << word << " ";
    }
    cout << endl;

    std::cout << Stoi64bit("82346973924") << std::endl;
    std::cout << Stoi64bit("-82346973924") << std::endl;
}