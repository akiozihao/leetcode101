//
// Created by akio on 2021/1/12.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int> &nums) {
        long t = 0;
        for (int &i:nums) {
            t ^= i;
        }
        t &= (-t);
        vector<int> res(2, 0);
        for (int &i:nums) {
            if (i & t) res[0] ^= i;
            else res[1] ^= i;
        }
        return res;
    }
};