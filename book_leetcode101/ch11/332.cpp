//
// Created by akio on 2021/1/14.
//
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>> &tickets) {
        vector<string> res;
        unordered_map<string, multiset<string>> m;
        for (auto a:tickets) {
            m[a[0]].insert(a[1]);
        }
        dfs(m, "JFK", res);
        return vector<string>(res.rbegin(), res.rend());
    }

private:
    void dfs(unordered_map<string, multiset<string>> &m, string start, vector<string> &res) {
        while (m[start].size()) {
            string t = *m[start].begin();
            m[start].erase(m[start].begin());
            dfs(m, t, res);
        }
        res.push_back(start);
    }
};