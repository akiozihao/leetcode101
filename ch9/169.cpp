//
// Created by akio on 2021/1/11.
//
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int cnt = 1, res = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == res) ++cnt;
            else --cnt;
            if (cnt < 0) {
                res = nums[i];
                cnt = 1;
            }
        }
        return res;
    }
};