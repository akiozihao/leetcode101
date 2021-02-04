//
// Created by akio on 2021/1/31.
//
#include <vector>

using namespace std;
using i64 = long long;
class Solution {
public:
    vector<bool> canEat(vector<int> &candiesCount, vector<vector<int>> &queries) {
        vector<long long> pre;
        pre.push_back(0);
        long long cnt = 0;
        for (auto c:candiesCount) {
            cnt += c;
            pre.push_back(cnt);
        }
        vector<bool> res;
        for (auto q:queries) {
            long long low = q[0]+1, high = (q[0]+1) * q[2], i = q[0];
            if (high < pre[i]+1 || low > pre[i+1]) res.push_back(false);
            else res.push_back(true);
        }
        return res;
    }
};