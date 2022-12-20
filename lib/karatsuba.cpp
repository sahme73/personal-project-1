#include "operations.h"

#include <stdexcept>

// TO DO: 
// 1 - run benchmarks

std::string Karatsuba(std::string x, std::string y) {
    std::string output = "";
    
    try {
        VerifyKaratsubaInput(x);
    } catch(const std::exception& e) {
        output += "Error: " + x + " input is not a valid number! ";
    }

    try {
        VerifyKaratsubaInput(y);
    } catch(const std::exception& e) {
        output += "Error: " + y + " input is not a valid number! ";
    }

    size_t max = std::to_string(LLONG_MAX).size();
    size_t x_size = GetNumDigits(x);
    size_t y_size = GetNumDigits(y);

    //check if inputs result in errors
    if ((x_size + y_size) >= max)
        output += "Error: overflow! ";
    if (x_size > max)
        output += "Error: (x) input is too large! ";
    if (y_size > max)
        output += "Error: (y) input is too large! ";
    
    //return errors or computation result
    return (output != "") ? output : KaratsubaHelper(x, y);
}

std::string KaratsubaHelper(std::string x, std::string y) {
    if (x.size() == 1 || y.size() == 1) {
        return std::to_string(VectorizedStoi64bit(x) * VectorizedStoi64bit(y));
    }

    if (x.at(0) == '-' && y.at(0) == '-') {
        x = x.substr(1, x.size() - 1);
        y = y.substr(1, y.size() - 1);
    }

    long long int middle = std::max(x.size(), y.size()) / 2;
    long long int a = VectorizedStoi64bit(x) / (long long int)(pow(10, middle));
    long long int b = VectorizedStoi64bit(x) % (long long int)(pow(10, middle));
    long long int c = VectorizedStoi64bit(y) / (long long int)(pow(10, middle));
    long long int d = VectorizedStoi64bit(y) % (long long int)(pow(10, middle));

    long long int ac = VectorizedStoi64bit(Karatsuba(std::to_string(a), std::to_string(c)));
    long long int bd = VectorizedStoi64bit(Karatsuba(std::to_string(b), std::to_string(d)));
    long long int ad_plus_bc = VectorizedStoi64bit(Karatsuba(std::to_string(a + b), std::to_string(c + d))) - ac - bd;

    return std::to_string(ac * ((long long int)pow(10, (2 * middle))) + (ad_plus_bc * ((long long int)pow(10, middle))) + bd);
}

void VerifyKaratsubaInput(std::string s) {
    for (size_t i = (s.at(0) == '-') ? 1 : 0; i < s.size(); i++) {
        if (s.at(i) < 48 || s.at(i) > 57)
            throw std::runtime_error("Error: " + s + " is not a valid number.");
    }
}