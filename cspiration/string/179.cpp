//
// Created by akio on 2021/2/20.
//
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string largestNumber(vector<int> &nums) {
        if (nums.empty()) return "";
        sort(nums.begin(), nums.end(), [](int &a, int &b) {
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });
        string res;
        for (int i:nums) {
            res += to_string(i);
        }
        return res[0] == '0' ? "0" : res;
    }
};