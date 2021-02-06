//
// Created by akio on 2021/2/5.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int> &nums) {
        int n = nums.size();
        vector<int> pre(n + 1, 0);
        for (int i = 1; i < pre.size(); ++i) {
            pre[i] = pre[i - 1] + nums[i - 1];
        }
        int res = 0;
        for (int i = 0; i < pre.size(); ++i) {
            for (int j = i; j < pre.size(); ++j) {
                res = max(res, abs(pre[j] - pre[i]));
            }
        }
        return res;
    }

    int maxAbsoluteSum2(vector<int> &nums) {
        int n = nums.size();
        vector<int> big(n, 0);
        vector<int> small(n, 0);
        big[0] = small[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            big[i] = max(big[i - 1] + nums[i], max(small[i - 1] + nums[i], nums[i]));
            small[i] = min(small[i - 1] + nums[i], min(big[i - 1] + nums[i], nums[i]));
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res = max(res, max(abs(big[i]), abs(small[i])));
        }
        return res;
    }

};