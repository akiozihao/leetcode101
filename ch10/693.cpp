//
// Created by akio on 2021/1/12.
//

class Solution {
public:
    bool hasAlternatingBits(int n) {
        return ((n ^= n / 4) & (n - 1)) == 0;
    }
};