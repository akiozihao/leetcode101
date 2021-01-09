//
// Created by akio on 2021/1/9.
//
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty() || prices.size() < 2) return 0;
        int n = prices.size();
        vector<vector<int>> buy(n, vector<int>(3));
        vector<vector<int>> sell(n, vector<int>(3));
        buy[0][0] = -prices[0];
        sell[0][0] = 0;
        for (int i = 1; i < 3; ++i) {
            buy[0][i] = sell[0][i] = INT_MIN / 2;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 3; ++j) {
                buy[i][j] = max(buy[i - 1][j], sell[i - 1][j] - prices[i]);
                sell[i][j] = max(sell[i - 1][j], buy[i - 1][j - 1] + prices[i]);
            }
        }
        return *max_element(sell[n - 1].begin(), sell[n - 1].end());
    }
};