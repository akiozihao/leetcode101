//
// Created by akio on 2021/1/26.
//
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> in(numCourses);
        for (auto p:prerequisites) {
            graph[p[1]].push_back(p[0]);
            ++in[p[0]];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (in[i] == 0) q.push(i);
        }
        vector<int> res;
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            res.push_back(t);
            for (int j:graph[t]) {
                --in[j];
                if (in[j] == 0) q.push(j);
            }
        }
        for (int i = 0; i < numCourses; ++i) {
            if (in[i] != 0) return {};
        }
        return res;
    }
};