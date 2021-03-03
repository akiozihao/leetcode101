//
// Created by akio on 2021/2/1.
//
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int hold = INT_MIN, sold = 0, res = 0;
        for (int &p:prices) {
            int pre_hold = hold;
            hold = max(hold, res - p);
            res = max(res, max(pre_hold, sold));
            sold = max(sold, pre_hold + p);
        }
        return max(res, sold);
    }
};