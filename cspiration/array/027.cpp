//
// Created by akio on 2021/1/26.
//
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int i = 0;
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                ++i;
            }
        }
        return i;
    }

    int removeElement2(vector<int> &nums, int val) {
        int i = 0, n = nums.size();
        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n - 1];
                --n;
            } else {
                ++i;
            }
        }
        return n;
    }

};