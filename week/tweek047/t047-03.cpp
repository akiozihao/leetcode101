#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int j = i;
            vector<int> cnt(26, 0);
            while (j < n && s[j] == s[i]) {
                ++cnt[s[j] - 'a'];
                ++j;
            }
            if (j == n) continue;
            while (j < n) {
                ++cnt[s[j] - 'a'];
                int mn = n + 1, mx = -1;
                for (int i = 0; i < 26; ++i) {
                    if (cnt[i] == 0) continue;
                    mx = max(mx, cnt[i]);
                    mn = min(mn, cnt[i]);
                }
                res += (mx - mn);
                ++j;
            };
        }
        return res;
    }
};