//
// Created by akio on 2021/1/28.
//
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        int mx = 0, last = 0, res = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i > last) {
                last = mx;
                ++res;
            }
            mx = max(mx, i + nums[i]);
        }
        return res;
    }
};