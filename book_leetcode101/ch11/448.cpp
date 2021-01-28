//
// Created by akio on 2021/1/12.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        vector<int> res;
        for (int num:nums) {
            int pos = abs(num) - 1;
            if (nums[pos] > 0)
                nums[pos] *= -1;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) res.push_back(i + 1);
        }
        return res;
    }
};