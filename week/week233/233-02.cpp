#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    using PII = pair<int, int>;
    int MOD = 1e9 + 7;
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<PII, vector<PII>, less<PII>> buypq;
        priority_queue<PII, vector<PII>, greater<PII>> sellpq;
        for (auto& order : orders) {
            // buy
            if (order[2] == 0) {
                while (order[1] > 0 && !sellpq.empty() &&
                       sellpq.top().first <= order[0]) {
                    if (order[1] > sellpq.top().second) {
                        order[1] -= sellpq.top().second;
                        sellpq.pop();
                    } else if (order[1] == sellpq.top().second) {
                        sellpq.pop();
                        order[1] == 0;
                    } else {
                        auto minsell = sellpq.top();
                        sellpq.pop();
                        sellpq.push({minsell.first, minsell.second - order[1]});
                        order[1] = 0;
                    }
                }
                if (order[1] > 0) buypq.push({order[0], order[1]});
            } else {
                // sell
                while (order[1] > 0 && !buypq.empty() &&
                       buypq.top().first >= order[0]) {
                    if (order[1] > buypq.top().second) {
                        order[1] -= buypq.top().second;
                        buypq.pop();
                    } else if (order[1] == buypq.top().second) {
                        buypq.pop();
                        order[1] = 0;
                    } else {
                        auto maxbuy = buypq.top();
                        buypq.pop();
                        buypq.push({maxbuy.first, maxbuy.second - order[1]});
                        order[1] = 0;
                    }
                }
                if (order[1] > 0) sellpq.push({order[0], order[1]});
            }
        }
        int res = 0;
        while (!buypq.empty()) {
            res = (res + buypq.top().second) % MOD;
            buypq.pop();
        }
        while (!sellpq.empty()) {
            res = (res + sellpq.top().second) % MOD;
            sellpq.pop();
        }
        return res;
    }
};