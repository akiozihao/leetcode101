#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<string> permutation(string s) {
        vector<string> res;
        string out;
        sort(s.begin(), s.end());
        vector<bool> visit(s.size(), false);
        dfs(s, 0, visit, out, res);
        return res;
    }

   private:
    void dfs(const string &s, int level, vector<bool> &visit, string &out,
             vector<string> &res) {
        if (level >= s.size()) {
            res.push_back(out);
            return;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (visit[i] || (i > 0 && s[i] == s[i - 1] && visit[i - 1]))
                continue;
            visit[i] = true;
            out += s[i];
            dfs(s, level + 1, visit, out, res);
            out.pop_back();
            visit[i] = false;
        }
    }
};