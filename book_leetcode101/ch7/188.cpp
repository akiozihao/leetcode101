//
// Created by akio on 2020/11/9.
//
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        if (prices.empty() || prices.size() < 2) return 0;
        int sz = prices.size();
        if (k >= sz)
            return helper(prices);
        vector<int> buy(k + 1, INT_MIN);
        vector<int> sell(k + 1, 0);
        for (int i = 0; i < sz; ++i) {
            for (int j = 1; j <= k; ++j) {
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k];
    }

private:
    int helper(const vector<int> &prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); ++i) {
            res += max(prices[i] - prices[i - 1], 0);
        }
        return res;
    }
};