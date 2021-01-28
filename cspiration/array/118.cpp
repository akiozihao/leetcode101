//
// Created by akio on 2021/1/28.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) return {};
        vector<vector<int>> res;
        res.push_back({1});
        for (int i = 2; i <= numRows; ++i) {
            vector<int> t;
            t.push_back(1);
            for (int j = 1; j < res.back().size(); ++j) {
                t.push_back(res.back()[j - 1] + res.back()[j]);
            }
            t.push_back(1);
            res.push_back(t);
        }
        return res;
    }

    vector<vector<int>> generate2(int numRows) {
        vector<vector<int>> res(numRows, vector<int>());
        for (int i = 0; i < numRows; ++i) {
            res[i].resize(i + 1,1);
            for (int j = 1; j < i; ++j) {
                res[i][j] = res[i-1][j-1] + res[i-1][j];
            }
        }
        return res;
    }

};