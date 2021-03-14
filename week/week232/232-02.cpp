#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findCenter(vector<vector<int>> &edges) {
        int res = 1;
        for (auto e : edges) {
            int u = e[0], v = e[1];
            if (res != u)
                res = v;
        }
        return res;
    }
};
