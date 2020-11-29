//
// Created by akio on 2020/11/29.
//
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>> &accounts) {
        long long total = 0;
        for (const auto &a:accounts) {
            long long t = accumulate(a.begin(), a.end(), 0);
            total = max(t,total);
        }
        return total;
    }
};