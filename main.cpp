#include <iostream>
#include <set>
#include <bitset>
using namespace std;

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size(), n = grid[0].size(), k = hits.size();
        vector<int> res(k), root(m * n, -1), count(m * n, 1), t(m * n, 0);
        vector<vector<int>> dirs{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (int i = 0; i < k; ++i) grid[hits[i][0]][hits[i][1]] -= 1;
        for (int i = 0; i < n; ++i) t[i] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 1) continue;
                if (i + 1 < m && grid[i + 1][j] == 1) {
                    int x = find(root, i * n + j), y = find(root, (i + 1) * n + j);
                    if (x != y) {root[y] = x; count[x] += count[y]; t[x] = t[y] = (t[x] | t[y]);}
                }
                if (j + 1 < n && grid[i][j + 1] == 1) {
                    int x = find(root, i * n + j), y = find(root, i * n + j + 1);
                    if (x != y) {root[y] = x; count[x] += count[y]; t[x] = t[y] = (t[x] | t[y]);}
                }
            }
        }
        for (int i = k - 1; i >= 0; --i) {
            int x = hits[i][0], y = hits[i][1], a = find(root, x * n + y), cnt = 0;
            if (++grid[x][y] != 1) continue;
            for (auto dir : dirs) {
                int newX = x + dir[0], newY = y + dir[1];
                if (newX < 0 || newX >= m || newY < 0 || newY >= n || grid[newX][newY] != 1) continue;
                int b = find(root, newX * n + newY);
                if (a == b) continue;
                if (!t[b]) cnt += count[b];
                root[b] = a; count[a] += count[b]; t[a] = t[b] = (t[a] | t[b]);
            }
            if (t[a]) res[i] = cnt;
        }
        return res;
    }
    int find(vector<int>& root, int x) {
        return (root[x] == -1) ? x : find(root, root[x]);
    }
};