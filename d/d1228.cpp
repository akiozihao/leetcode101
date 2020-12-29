//
// Created by akio on 2020/12/28.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        if (prices.empty()) return 0;
        int n = prices.size();
        if (k > n / 2) return helper(prices);
        vector<vector<int>> buy(n, vector<int>(k + 1));
        vector<vector<int>> sell(n, vector<int>(k + 1));
        buy[0][0] = -prices[0];
        sell[0][0] = 0;
        for (int j = 1; j <= k; ++j) {
            buy[0][j] = INT_MIN / 2;
            sell[0][j] = INT_MIN / 2;
        }
        for (int i = 1; i < n; ++i) {
            buy[i][0] = max(buy[i - 1][0], sell[i - 1][0] - prices[i]);
            for (int j = 1; j <= k; ++j) {
                buy[i][j] = max(buy[i - 1][j], sell[i - 1][j] - prices[i]);
                sell[i][j] = max(sell[i - 1][j], buy[i - 1][j - 1] + prices[i]);
            }
        }
        return *max_element(sell[n - 1].begin(), sell[n - 1].end());
    }

private:
    int helper(const vector<int> &prices) {
        int n = prices.size();
        int res = 0;
        for (int i = 1 ;i < n; ++i) {
            res += max(0, prices[i] - prices[i - 1]);
        }
        return res;
    }
};