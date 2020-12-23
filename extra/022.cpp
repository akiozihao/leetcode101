//
// Created by akio on 2020/12/23.
//
#include <vector>

using namespace std;

class NumMatrix {
public:
    vector<vector<int>> d;

    NumMatrix(vector<vector<int>> &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        d = vector<vector<int>>(m, vector<int>(n, 0));
        d[0][0] = matrix[0][0];
        for (int i = 1; i < m; ++i) {
            d[i][0] = d[i - 1][0] + matrix[i][0];
        }
        for (int j = 1; j < n; ++j) {
            d[0][j] = d[0][j - 1] + matrix[0][j];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                d[i][j] = d[i - 1][j] + d[i][j - 1] - matrix[i - 1][j - 1] + matrix[i][j];
            }
        }
        cout << m << ' ' << n << endl;;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        cout << row1 << ' ' << col1 << ' ' << row2 << ' ' << col2 << ' ' << sum[row2][col2] << endl;
        int ret = d[row2][col2];
        cout << ret << endl;
        if (row1 - 1 >= 0) {
            ret -= d[row1 - 1][col2];
        }
        cout << 'x' << endl;
        if (col1 - 1 >= 0) {
            ret -= sum[row2][col1 - 1];
        }
        cout << 'xx' << endl;
        if (row1 - 1 >= 0 && col1 - 1 >= 0) {
            ret += sum[row1 - 1][col1 - 1];
        }
        cout << 'xxx' << endl;
        return ret;

    }
};