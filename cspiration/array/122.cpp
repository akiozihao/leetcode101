//
// Created by akio on 2021/1/28.
//
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); ++i) {
            res += max(0,prices[i]-prices[i-1]);
        }
        return res;
    }
};