#include <string>
#include <math.h>

/*
    Multiply two large integer numbers using divide-and-conquer.
    Note: limited to 64-bit integers.
    Runtime: O(n^1.585)
    Reference: https://iq.opengenus.org/karatsuba-algorithm/
*/
std::string Karatsuba(std::string x, std::string y);
std::string KaratsubaHelper(std::string x, std::string y);