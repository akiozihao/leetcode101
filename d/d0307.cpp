#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1]))
                    dp[i][j] = true;
            }
        }
        vector<vector<string>> res;
        vector<string> t;
        dfs(s, res, dp, t, 0);
        return res;
    }

private:
    void dfs(string &s, vector<vector<string>> &res, vector<vector<bool>> dp,
             vector<string> &t, int idx) {
        if (idx == dp.size()) {
            res.push_back(t);
            return;
        }
        for (int i = idx; i < dp.size(); ++i) {
            if (dp[idx][i]) {
                t.push_back(s.substr(idx, i - idx + 1));
                dfs(s, res, dp, t, i + 1);
                t.pop_back();
            }
        }
    }
};

int main() {
    string x = "aab";
    Solution s;
    auto v = s.partition(x);
    for (auto i : v) {
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }
}