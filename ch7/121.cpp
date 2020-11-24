//
// Created by akio on 2020/11/2.
//
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int sell = 0, buy = INT_MIN;
        for (int price:prices) {
            buy = max(buy, -price);
            sell = max(sell, buy + price);
        }
        return sell;
    }
};