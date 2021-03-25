#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        int l_mn = nums[0];
        multiset<int> right_all;
        for (int k = 2; k < n; ++k) {
            right_all.insert(nums[k]);
        }
        for (int i = 1; i < n - 1; ++i) {
            if (l_mn < nums[i]) {
                auto it = upper_bound(right_all.begin(), right_all.end(), l_mn);
                if (it != right_all.end() && *it < nums[i]) {
                    return true;
                }
            }
            l_mn = min(l_mn, nums[i]);
            right_all.erase(right_all.find(nums[i + 1]));
        }
        return false;
    }
    bool find132pattern2(vector<int>& nums) {
        int n = nums.size();
        stack<int> stk;
        stk.push(nums[n - 1]);
        int max_k = INT_MIN;
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < max_k) return true;
            while (!stk.empty() && nums[i] > stk.top()) {
                max_k = stk.top();
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};