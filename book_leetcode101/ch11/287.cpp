//
// Created by akio on 2021/1/14.
//
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int n = nums.size(), l = 1, r = n;
        while (l < r) {
            int m = l + (r - l) / 2;
            int cnt = 0;
            for (int &i:nums) {
                if (i <= m) ++cnt;
            }
            if (cnt <= m) l = m + 1;
            else r = m;
        }
        return r;
    }

    int findDuplicate2(vector<int> &nums) {
        int res = 0, n = nums.size();
        for (int i = 0; i < 32; ++i) {
            int bit = (1 << i), cnt1 = 0, cnt2 = 0;
            for (int k = 0; k < n; ++k) {
                if (bit & k) ++cnt1;
                if (bit & nums[k]) ++cnt2;
            }
            if (cnt2 > cnt1) res += bit;
        }
        return res;
    }

};