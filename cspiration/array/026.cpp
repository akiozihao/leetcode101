//
// Created by akio on 2021/1/26.
//
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int i = 0;
        for (int num:nums) {
            if (i < 1 || num > nums[i - 1]) {
                nums[i++] = num;
            }
        }
        return i;
    }
};