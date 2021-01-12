//
// Created by akio on 2021/1/11.
//

#include <cmath>

class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (int(log10(n) / log10(4)) - log10(n) / log10(4) == 0);
    }
};