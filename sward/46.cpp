#include <vector>
using namespace std;
class Solution {
   public:
    int translateNum(int num) {
        vector<int> v;
        while (num) {
            v.push_back(num % 10);
            num /= 10;
        }
        int n = v.size();
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1];
            if (v[i - 1] > 0 && (v[i - 1] * 10 + v[i] < 25)) dp[i] += dp[i - 2];
        }
        return dp.back();
    }
};