#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int movingCount(int m, int n, int k) {
        if (k == 0) return 1;
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        q.push(make_pair(0, 0));
        vis[0][0] = true;
        int res = 1;
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (auto &dir : dirs) {
                int x = i + dir[0], y = j + dir[1];
                if (x < 0 || x >= m || y < 0 || y >= n || vis[x][y] ||
                    get(x) + get(y) > k)
                    continue;
                q.push(make_pair(x, y));
                vis[x][y] = true;
                ++res;
            }
        }
        return res;
    }

   private:
    vector<vector<int>> dirs{{0, 1}, {1, 0}};
    int get(int x) {
        int res = 0;
        while (x) {
            res += x % 10;
            x /= 10;
        }
        return res;
    }
};