//
// Created by akio on 2021/2/20.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canChoose(vector<vector<int>> &groups, vector<int> &nums) {
        for (int i = 0, k = 0; i < nums.size(); ++i) {
            if (check(groups[k], nums, i)) {
                i += (int) groups[k].size() - 1;
                ++k;
                if (k == groups.size()) return true;
            }
        }
        return false;
    }

private:
    bool check(vector<int> &g, vector<int> &nums, int i) {
        int x, y;
        for (x = 0, y = i; x < g.size() && y < nums.size(); ++x, ++y) {
            if (g[x] != nums[y]) break;
        }
        if (x != g.size()) return false;
        return true;
    }
};