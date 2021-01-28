//
// Created by akio on 2020/10/29.
//
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int res = 0;
        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                    res = max(res,dp[i][j]);
                }
            }
        }
//        for (int i = 0; i < m + 1; ++i) {
//            for (int j = 0; j < n + 1; ++j) {
//                cout << dp[i][j] << " ";
//            }
//            cout << endl;
//        }
        return res;
    }
};