#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        int m = matrix.size(), n = matrix[0].size();
        bool row = false, col = false;
        for (int i = 0; i < m; ++i) {
            if (!matrix[i][0]) col = true;
        }
        for (int j = 0; j < n; ++j) {
            if (!matrix[0][j]) row = true;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (!matrix[i][j]) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (!matrix[0][j] || !matrix[i][0]) matrix[i][j] = 0;
            }
        }
        if (row) {
            for (int j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }
        if (col) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};