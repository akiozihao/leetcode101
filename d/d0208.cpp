//
// Created by akio on 2021/2/8.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int> &arr) {
        if (arr.empty()) return 0;
        int n = arr.size();
        vector<int> up(n, 1), down(n, 1);
        for (int i = 1; i < n; ++i) {
            if (arr[i] > arr[i - 1]) {
                up[i] = down[i - 1] + 1;
            } else if (arr[i] < arr[i - 1]) {
                down[i] = up[i - 1] + 1;
            }
        }
        return max(*max_element(up.begin(), up.end()), *max_element(down.begin(), down.end()));
    }
};