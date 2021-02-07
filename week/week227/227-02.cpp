//
// Created by akio on 2021/2/5.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumScore2(int a, int b, int c) {
        vector<int> v{a, b, c};
        sort(v.begin(), v.end());
        int res = 0;
        while (v[1] > 0) {
            res += 1;
            --v[1];
            --v[2];
            sort(v.begin(), v.end());
        }
        return res;
    }

};