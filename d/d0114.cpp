//
// Created by akio on 2021/1/14.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int> &A) {
        if (A.empty()) return {};
        vector<bool> res;
        int prefix = A[0];
        res.push_back(prefix % 5 == 0);
        for (int i = 1; i < A.size(); ++i) {
            prefix = ((prefix << 1) + A[i]) % 5;
            res.push_back(prefix % 5 == 0);
        }
        return res;
    }
};