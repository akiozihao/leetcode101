//
// Created by akio on 2021/1/7.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        if (isConnected.empty() || isConnected[0].empty()) return 0;
        int p = isConnected.size();
        vector<bool> visited(p, false);
        int res = 0;
        for (int i = 0; i < p; ++i) {
            if (!visited[i]) {
                dfs(isConnected, visited, p, i);
                ++res;
            }
        }
        return res;
    }

private:
    void dfs(vector<vector<int>> &isConnected, vector<bool> &visited, int p, int i) {
        for (int j = 0; j < p; ++j) {
            if (isConnected[i][j] == 1 && !visited[j]) {
                visited[j] = true;
                dfs(isConnected, visited, p, j);
            }
        }
    }
};