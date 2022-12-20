#pragma once

#include <string>
#include <math.h>

/*
 *  Multiply two large integer numbers using divide-and-conquer.
 *  Note: limited to 64-bit integers.
 *  Runtime: O(n^1.585)
 *  Reference: https://iq.opengenus.org/karatsuba-algorithm/
 */
std::string Karatsuba(std::string x, std::string y);
std::string KaratsubaHelper(std::string x, std::string y);

/*
 *  Upgraded string to 64-bit integer.
 */
long long int Stoi64bit(std::string s);
long long int VectorizedStoi64bit(std::string s);