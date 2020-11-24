//
// Created by akio on 2020/11/10.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 2; i <= n; ++i) {
            int curmax = 0;
            for (int j = 1; j < i; ++j) {
                curmax = max(curmax, max(j * (i - j), j * dp[i - j]));
            }
            dp[i] = curmax;
        }
        return dp.back();
    }
};

int main() {
    Solution s;
    cout << s.integerBreak(10) << endl;
}