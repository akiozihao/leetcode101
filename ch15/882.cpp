//
// Created by akio on 2021/1/26.
//
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int reachableNodes(vector<vector<int>> &edges, int M, int N) {
        int res = 0;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        vector<bool> visited(N);
        priority_queue<pair<int, int>> pq;
        pq.push({M, 0});
        for (auto &edge:edges) {
            graph[edge[0]][edge[1]] = edge[2];
            graph[edge[1]][edge[0]] = edge[2];
        }
        while (!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            int move = t.first, cur = t.second;
            if (visited[cur]) continue;
            visited[cur] = true;
            ++res;
            for (int i = 0; i < N; ++i) {
                if (graph[cur][i] == -1) continue;
                if (move > graph[cur][i] && !visited[i]) {
                    pq.push({move - graph[cur][i] - 1, i});
                }
                graph[i][cur] -= min(move, graph[cur][i]);
                res += min(move, graph[cur][i]);
            }
        }
        return res;
    }
};