//
// Created by akio on 2020/12/29.
//
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> sum(m, vector<int>(n, 0));
        int res = INT_MIN;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int t = matrix[i][j];
                if (i > 0) t += sum[i - 1][j];
                if (j > 0) t += sum[i][j - 1];
                if (i > 0 && j > 0) t -= sum[i - 1][j - 1];
                sum[i][j] = t;
                for (int r = 0; r <= i; ++r) {
                    for (int c = 0; c <= j; ++c) {
                        int d = sum[i][j];
                        if (r > 0) d -= sum[r - 1][j];
                        if (c > 0) d -= sum[i][c - 1];
                        if (r > 0 && c > 0) d += sum[r - 1][c - 1];
                        if (d <= k) res = max(res, d);
                    }
                }
            }
        }
        return res;
    }

    int maxSumSubmatrix2(vector<vector<int>> &matrix, int k) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(),res = INT_MIN;
        // 枚举左边界
        for(int l=0; l < n; ++l){
            vector<int> sum(m);
            // 枚举右边界
            for(int r=l; r < n; ++r){
                for(int i=0; i < m; ++i){
                    // 按行累计
                    sum[i] += matrix[i][r];
                }
                int curSum = 0;
                set<int> st({0});
                for(int a:sum){
                    curSum += a;
                    auto it = st.lower_bound(curSum-k);
                    if(it!=st.end()) res = max(res,curSum-*it);
                    st.insert(curSum);
                }
            }
        }
        return res;
    }


};