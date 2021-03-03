//
// Created by akio on 2021/2/1.
//
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        if (height.empty() || height.size() < 2) return 0;
        int res = 0, l = 0, r = height.size() - 1, h;
        while (l < r) {
            h = min(height[l], height[r]);
            res = max(res, h * (r - l));
            height[l] > height[r] ? --r : ++l;
        }
        return res;
    }
};