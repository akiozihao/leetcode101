//
// Created by akio on 2020/11/10.
//
#include <vector>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int> &nums) {
        if (nums.empty()) return 0;
        int sz = nums.size();
        vector<int> up(sz, 1);
        vector<int> down(sz, 1);
        int res = 1;
        for (int i = 1; i < sz; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j])
                    up[i] = max(up[i], down[j] + 1);
                else if (nums[i] < nums[j])
                    down[i] = max(down[i], up[j] + 1);
            }
            res = max(up[i], down[i]);
        }
        return res;
    }
};