#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> exchange(vector<int> &nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            while (l < r && nums[l] & 1) ++l;
            while (l < r && (nums[r] & 1) == 0) --r;
            if (l < r) {
                swap(nums[l++], nums[r--]);
            }
        }
        return nums;
    }
};