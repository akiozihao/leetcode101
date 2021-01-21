//
// Created by akio on 2021/1/19.
//
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> v(m, vector<int>(n + 1, 0));
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                if (matrix[i][j] == '1') {
                    v[i][j] = ((i == 0) ? 0 : v[i - 1][j]) + 1;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < m; ++i) {
            stack<int> st;
            for (int j = 0; j < n + 1; ++j) {
                while (!st.empty() && v[i][st.top()] > v[i][j]) {
                    int cur = st.top();
                    st.pop();
                    int left = st.empty() ? 0 : st.top() + 1;
                    int right = j - 1;
                    res = max(res,v[i][cur] * (right-left+1));
                }
                st.push(j);
            }
        }
        return res;
    }
};