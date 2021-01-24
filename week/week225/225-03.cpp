//
// Created by akio on 2021/1/23.
//
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>

using namespace std;

struct t {
    bool operator()(int &a, int b) {
        return a < b;
    }
};

class Solution {
public:
    int kthLargestValue(vector<vector<int>> &matrix, int k) {
        set<int, t> st;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        unordered_set<int> ss;
        dp[0][0] = matrix[0][0];
        st.insert(dp[0][0]);
        for (int i = 1; i < m; ++i) {
            dp[i][0] = dp[i - 1][0] ^ matrix[i][0];
            st.insert(dp[i][0]);
        }
        for (int j = 1; j < n; ++j) {
            dp[0][j] = dp[0][j - 1] ^ matrix[0][j];
            st.insert(dp[0][j]);
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i - 1][j] ^ dp[i][j - 1] ^ matrix[i][j] ^ matrix[i - 1][j - 1];
                st.insert(dp[i][j]);
            }
        }
        auto it = st.begin();
        for (int i = 1; i <= k; ++i) {
            ++it;
        }
        return *it;
    }

    int kthLargestValue2(vector<vector<int>> &matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        vector<int> res;
        res.reserve(n * m);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int t = matrix[i][j];
                if (i > 0) {
                    t ^= dp[i - 1][j];
                }
                if (j > 0) {
                    t ^= dp[i][j - 1];
                }
                if (i > 0 && j > 0) {
                    t ^= dp[i - 1][j - 1];
                }
                dp[i][j] = t;
                res.push_back(t);
            }
        }
        k = n * m - k;
        nth_element(res.begin(), res.begin() + k, res.end());
        return res[k];
    }
};

[[10,9,5],[2,0,4],[1,0,9],[3,4,8]]
10