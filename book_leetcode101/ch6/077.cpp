//
// Created by akio on 2020/10/25.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tmp;
        helper(n, k, res, tmp, 1);
        return res;
    }

private:
    void helper(int n, int k, vector<vector<int>> &res, vector<int> &tmp, int idx) {
        if (tmp.size() == k) {
            res.push_back(tmp);
            return;
        }
        for (int i = idx; i <= n; ++i) {
            tmp.push_back(i);
            helper(n, k, res, tmp, i + 1);
            tmp.pop_back();
        }
    }
};