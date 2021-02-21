//
// Created by akio on 2021/2/18.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string res;
        if (strs.empty()) return res;
        int m = strs.size(), n = strs[0].size();
        for (int i = 0; i < n; ++i) {
            char c = strs[0][i];
            for (int j = 1; j < m; ++j) {
                if (i > strs[j].size() || c != strs[j][i]) return res;
            }
            res.push_back(c);
        }
        return res;
    }
};