//
// Created by akio on 2021/2/16.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
        vector<string> res;
        for (int num:nums) {
            if (num > lower)
                res.push_back(to_string(lower) +
                              (num - 1 > lower ? ("->" + to_string(num - 1)) : ""));
            if (num == upper)return res;
            lower = num + 1;
        }
        if (lower <= upper)
            res.push_back(to_string(lower) +
                          (upper > lower ? ("->" + to_string(upper)) : ""));
        return res;
    }
};