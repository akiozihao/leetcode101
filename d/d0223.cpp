#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int X) {
        if (customers.empty()) return 0;
        int n = customers.size();
        vector<int> score(n, 0);
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0) score[i] = customers[i];
        }
        vector<int> go(n + 1, 0), back(n + 1, 0), pre(n + 1, 0);
        int cur = 0;
        // go[i] --> score[0,i-1]
        for (int i = 1; i <= n; ++i) {
            go[i] = go[i - 1] + score[i - 1];
            pre[i] = pre[i - 1] + customers[i - 1];
        }
        // back[i] --> score[i,n-1]
        for (int i = n - 1; i >= 0; --i) {
            back[i] = back[i + 1] + score[i];
        }
        int res = pre[X];
        for (int i = X - 1; i < n; ++i) {
            int l = go[i - X + 1];
            int r = back[i + 1];
            int m = pre[i + 1] - pre[i - X + 1];
            res = max(res, l + r + m);
        }
        return res;
    }
};
