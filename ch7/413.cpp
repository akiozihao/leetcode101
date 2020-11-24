//
// Created by akio on 2020/10/28.
//
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &A) {
        int sz = A.size();
        if (sz < 3) return 0;
        vector<int> dp(sz, 0);
        for (int i = 2; i < sz; ++i) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
                dp[i] = dp[i - 1] + 1;
        }
        return accumulate(dp.begin(),dp.end(),0);
    }
};