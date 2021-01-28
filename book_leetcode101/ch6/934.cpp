//
// Created by akio on 2020/10/27.
//
#include <vector>
#include <queue>
#include <climits>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> dir{-1, 0, 1, 0, -1};

    int shortestBridge(vector<vector<int>> &A) {
        int m = A.size(), n = A[0].size();
        queue<pair<int, int>> points;
        bool finded = false;
        for (int i = 0; i < m; ++i) {
            if(finded) break;
            for (int j = 0; j < n; ++j) {
                if (A[i][j] == 1) {
                    findfirst(points, A, i, j);
                    finded=true;
                    break;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << A[i][j] << ' ';
            }
            cout << endl;
        }
        int x, y;
        int level = 0;
        cout << points.size() << endl;
        while (!points.empty()) {
            ++level;
            int sz = points.size();
            while (sz) {
                auto p = points.front();
                points.pop();
                int r = p.first, c = p.second;
                for (int i = 0; i < 4; ++i) {
                    x = r + dir[i], y = c + dir[i + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        if (A[x][y] == 1) return level;
                        if (A[x][y] == -1 || A[x][y] == 2) continue;
                        points.push({x, y});
                        A[x][y] = -1;
                    }
                }
                --sz;
            }
        }
        return 0;
    }

private:
    void findfirst(queue<pair<int, int>> &points, vector<vector<int>> &A, int i, int j) {
        int m = A.size(), n = A[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n) return;
        if (A[i][j] == 0) {
            points.push({i, j});
            A[i][j] = 2;
            return;
        }
        if (A[i][j] == 1) {
            A[i][j] = -1;
            findfirst(points, A, i - 1, j);
            findfirst(points, A, i + 1, j);
            findfirst(points, A, i, j - 1);
            findfirst(points, A, i, j + 1);
        }
    }
};