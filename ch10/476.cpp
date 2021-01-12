//
// Created by akio on 2021/1/12.
//

#include <climits>

class Solution {
public:
    int findComplement(int num) {
        bool flag = false;
        for (int i = 31; i >= 0; --i) {
            if (num & (1 << i)) flag = true;
            if (flag) num ^= (1 << i);
        }
        return num;
    }

    int findComplement2(int num) {
        unsigned int mask = UINT_MAX;
        while (mask & num) mask <<= 1;
        return ~mask & ~num;
    }

};