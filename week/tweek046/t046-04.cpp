//
// Created by akio on 2021/2/20.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getCoprimes(vector<int> &nums, vector<vector<int>> &edges) {
        int n = nums.size();
        vector<vector<int>> graph(n);
        for (auto e:edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        // vl,pair<node,depth>
        map<int, pair<int, int>> ancestors;
        vector<int> res(n, -1);
        dfs(0, nums, graph, res, ancestors, 0, -1);
        return res;
    }

private:
    void dfs(int node, vector<int> &nums, vector<vector<int>> &graph,
             vector<int> &res, map<int, pair<int, int>> &ancestors, int depth, int father) {
        int closest_ancestor = -1;
        int distance = INT_MAX;
        for (auto p:ancestors) {
            if (__gcd(p.first, nums[node]) == 1 && (depth - p.second.second) < distance) {
                distance = depth - p.second.second;
                closest_ancestor =p.second.first;
            }
        }
        res[node] = closest_ancestor;
        bool has_original_ancestor = (ancestors.count(nums[node])) > 0;
        pair<int, int> original_node = ancestors[nums[node]];
        ancestors[nums[node]] = {node, depth};
        for (int neighbor : graph[node]) {
            if (neighbor == father) continue;
            dfs(neighbor, nums, graph, res, ancestors, depth + 1, node);
        }
        ancestors.erase(nums[node]);
        if (has_original_ancestor) ancestors[nums[node]] = original_node;
    }
};