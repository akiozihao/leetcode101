//
// Created by akio on 2021/1/26.
//
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>> &graph) {
        if (graph.empty()) return true;
        int n = graph.size();
        vector<int> color(n, 0);
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (color[i] == 0) {
                q.push(i);
                color[i] = 1;
            }
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (const int &j:graph[node]) {
                    if (color[j] == 0) {
                        q.push(j);
                        color[j] = color[node] == 2 ? 1 : 2;
                    } else if (color[node] == color[j]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool isBipartite2(vector<vector<int>> &graph) {
        if (graph.empty()) return true;
        int n = graph.size();
        vector<int> color(n, 0);
        queue<int> q;
        q.push(0);
        color[0] = 1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int &j:graph[node]) {
                if (color[j] == 0) {
                    color[j] = color[node] == 1 ? 2 : 1;
                    q.push(j);
                } else if (color[node] == color[j]) return false;
            }
        }
        return true;
    }
};