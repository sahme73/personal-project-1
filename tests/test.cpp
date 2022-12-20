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
    std::cout << Stoi64bit("123") << std::endl;
    std::cout << Stoi64bit("12") << std::endl;
    std::cout << Stoi64bit("3") << std::endl;
    std::cout << Stoi64bit("321") << std::endl;
    std::cout << Stoi64bit("21") << std::endl;
    
    std::cout << VectorizedStoi64bit("82346973924") << std::endl;
    std::cout << VectorizedStoi64bit("-82346973924") << std::endl;
    std::cout << VectorizedStoi64bit("123") << std::endl;
    std::cout << VectorizedStoi64bit("12") << std::endl;
    std::cout << VectorizedStoi64bit("3") << std::endl;
    std::cout << VectorizedStoi64bit("321") << std::endl;
    std::cout << VectorizedStoi64bit("21") << std::endl;

}