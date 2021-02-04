//
// Created by akio on 2021/1/31.
//
#include <vector>

using namespace std;

using i64 = long long;
class Solution {
public:
    vector<bool> canEat(vector<int> &candiesCount, vector<vector<int>> &queries) {
        int n = candiesCount.size();
        vector<i64> s(n + 1);
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + candiesCount[i];
        }
        vector<bool> res;
        for (auto q:queries) {
            i64 min_s = s[q[0]] + 1;
            i64 max_s = s[q[0] + 1];
            i64 day = q[1];
            i64 cap = q[2];
            i64 min_t = day + 1;
            i64 max_t = (day + 1) * cap;
            res.push_back(!(min_s > max_t || max_s < min_t));
        }
        return res;
    }
};