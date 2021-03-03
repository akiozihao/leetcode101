//
// Created by akio on 2021/2/17.
//
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = nums.size(), r = nums.size() -1 ;
        while (l < r) {
            int m = l + (r-l)/2;
            if(nums[m]  > nums[r]) l = m  +1;
            else r = m;
        }
        return nums[r];
    }
};