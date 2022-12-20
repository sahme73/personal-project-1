#include "operations.h"

long long int Stoi64bit(std::string s) {
    
    if (s.size() == 0)
        return 0;

    long long int output = 0;
    long long int base = 1;

    for (int i = (int)s.size() - 1; i >= 0; i--) {

        if (s.at(i) == '-') {
            output *= -1;
            continue;
        }

        output += ((((int)s.at(i)) - 48) * base);
        base *= 10;
    }

    return output;

}