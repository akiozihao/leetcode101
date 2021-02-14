//
// Created by akio on 2021/2/14.
//
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minSwapsCouples(vector<int> &row) {
        unordered_map<int, int> m;
        for (int i = 0; i < row.size(); ++i) {
            m[row[i]] = i;
        }
        int res = 0;
        for (int i = 0; i < row.size(); i += 2) {
            if (row[i + 1] != (row[i] ^ 1)) {
                ++res;
                int t = m[row[i] ^ 1];
                m[row[i + 1]] = t;
                swap(row[i + 1], row[t]);
            }
        }
        return res;
    }
};