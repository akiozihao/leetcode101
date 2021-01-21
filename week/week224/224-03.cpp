//
// Created by akio on 2021/1/17.
//
#include <vector>
#include <climits>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<vector<int>> cnt(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    cnt[i][j] = ((i == 0) ? 0 : cnt[i - 1][j]) + 1;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            vector<int> &row = cnt[i];
            sort(row.begin(), row.end(), [](int &a, int &b) {
                return a < b;
            });
//            for (auto c:row) {
//                cout << c << ' ';
//            }
//            cout << endl;
            for (int j = 0; j < n; ++j) {
                if (row[j] == 0) break;
                res = max(res, row[j] * (j + 1));
            }
        }
        return res;
    }
};