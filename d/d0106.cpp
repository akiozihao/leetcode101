//
// Created by akio on 2021/1/6.
//
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<double>
    calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
        vector<double> res;
        unordered_map<string, unordered_map<string, double>> m;
        for (int i = 0; i < equations.size(); ++i) {
            m[equations[i][0]].emplace(equations[i][1], values[i]);
            m[equations[i][0]].emplace(equations[i][0], 1.0);
            m[equations[i][1]].emplace(equations[i][0], 1.0 / values[i]);
            m[equations[i][1]].emplace(equations[i][1], 1.0);
        }
        for (auto query:queries) {
            if (!m.count(query[0]) || !m.count(query[1])) {
                res.push_back(-1.0);
                continue;
            }
            queue<pair<string, double>> q;
            unordered_set<string> visited{query[0]};
            bool found = false;
            q.push({query[0], 1.0});
            while (!q.empty() && !found) {
                for (int i = q.size(); i > 0; --i) {
                    auto t = q.front();
                    q.pop();
                    if (t.first == query[1]) {
                        found = true;
                        res.push_back(t.second);
                        break;
                    }
                    for (auto a:m[t.first]) {
                        if(visited.count(a.first)) continue;
                        visited.insert(a.first);
                        a.second *= t.second;
                        q.push(a);
                    }
                }
            }
            if(!found) res.push_back(-1.0);
        }
        return res;
    }
};