#include "operations.h"

// TO DO: 
// 1 - fix s1 error
// 2 - clean up functions
// 3 - run benchmarks

std::string Karatsuba(std::string x, std::string y) {

    std::string output = "";
    size_t max = std::to_string(LLONG_MIN).size();

    if (x.size() < (max - 2) && y.size() < (max - 2)) {
        output = KaratsubaHelper(x, y);

    }

    if (x.size() > max) {
        output += "Error: first input is too large! ";
    }

    if (y.size() > max) {
        output += "Error: second input is too large! ";
    }

    if (output != "") {
        return output;
    }

    //both inputs have the same number of digits as the maximum
    std::string minimum = std::to_string(LLONG_MIN); //-9223372036854775808
    std::string maximum = std::to_string(LLONG_MAX); // 9223372036854775807

    //check x:

    //check y:

    return "Error: s1 ";
    
}

std::string KaratsubaHelper(std::string x, std::string y) {

    if (x.size() == 1 || y.size() == 1) {
        return std::to_string(Stoi64bit(x) * Stoi64bit(y));
    }

    if (x.at(0) == '-' && y.at(0) == '-') {
        x = x.substr(1, x.size() - 1);
        y = y.substr(1, y.size() - 1);
    }

    long long int middle = std::max(x.size(), y.size()) / 2;
    long long int a = Stoi64bit(x) / (long long int)(pow(10, middle));
    long long int b = Stoi64bit(x) % (long long int)(pow(10, middle));
    long long int c = Stoi64bit(y) / (long long int)(pow(10, middle));
    long long int d = Stoi64bit(y) % (long long int)(pow(10, middle));

    long long int ac = Stoi64bit(Karatsuba(std::to_string(a), std::to_string(c)));
    long long int bd = Stoi64bit(Karatsuba(std::to_string(b), std::to_string(d)));
    long long int ad_plus_bc = Stoi64bit(Karatsuba(std::to_string(a + b), std::to_string(c + d))) - ac - bd;

    return std::to_string(ac * ((long long int)pow(10, (2 * middle))) + (ad_plus_bc * ((long long int)pow(10, middle))) + bd);

}