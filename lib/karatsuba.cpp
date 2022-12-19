#include "operations.h"

// TO DO: 
// 1 - create a custom stoi for 64-bit values
// 2 - fix s1 error
// 3 - clean up functions
// 4 - run benchmarks

std::string Karatsuba(std::string x, std::string y) {

    //size_t max = std::to_string(LLONG_MIN).size();
    size_t max = std::to_string(INT32_MIN).size();

    if (x.size() < (max - 2) && y.size() < (max - 2)) {
        return KaratsubaHelper(x, y);
    }

    std::string output = "";

    if (x.size() > max) {
        output += " Error: first input is too large!";
    }

    if (y.size() > max) {
        output += " Error: second input is too large!";
    }

    if (output != "") {
        return output;
    }

    //both inputs have the same number of digits as the maximum
    std::string minimum = std::to_string(LLONG_MIN); //-9223372036854775808
    std::string maximum = std::to_string(LLONG_MAX); // 9223372036854775807

    //check x:

    //check y:

    return " Error: s1";
    
}

std::string KaratsubaHelper(std::string x, std::string y) {

    if (x.size() == 1 || y.size() == 1) {
        return std::to_string(std::stoi(x) * std::stoi(y));
    }

    if (x.at(0) == '-' && y.at(0) == '-') {
        x = x.substr(1, x.size() - 1);
        y = y.substr(1, y.size() - 1);
    }

    long long int middle = std::max(x.size(), y.size()) / 2;
    long long int a = std::stoi(x) / (int)(pow(10, middle));
    long long int b = std::stoi(x) % (int)(pow(10, middle));
    long long int c = std::stoi(y) / (int)(pow(10, middle));
    long long int d = std::stoi(y) % (int)(pow(10, middle));

    long long int ac = std::stoi(Karatsuba(std::to_string(a), std::to_string(c)));
    long long int bd = std::stoi(Karatsuba(std::to_string(b), std::to_string(d)));
    long long int ad_plus_bc = std::stoi(Karatsuba(std::to_string(a + b), std::to_string(c + d))) - ac - bd;

    return std::to_string(ac * pow(10, (2 * middle)) + (ad_plus_bc * pow(10, middle)) + bd);

}