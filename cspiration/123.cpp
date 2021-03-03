//
// Created by akio on 2021/1/28.
//
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty() || prices.size() < 2) return 0;
        int k = 2, n = prices.size();
        vector<vector<int>> buy(n, vector<int>(k + 1));
        vector<vector<int>> sell(n, vector<int>(k + 1));
        buy[0][0] = -prices[0];
        sell[0][0] = 0;
        for (int j = 1; j <= k; ++j) {
            buy[0][j] = sell[0][j] = INT_MIN;
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
};