//
// Created by akio on 2021/1/28.
//
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int res = nums[0], cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == res) ++cnt;
            else {
                --cnt;
                if (cnt < 0) {
                    cnt = 0;
                    res = nums[i];
                }
            }
        }
        return res;
    }

    int majorityElement2(vector<int> &nums) {
        int res = 0, cnt = 0;
        for (int num:nums) {
            if (res == num) ++cnt;
            else if (cnt == 0) {
                res = num;
                cnt = 1;
            } else {
                --cnt;
            }
        }
        return res;
    }
};