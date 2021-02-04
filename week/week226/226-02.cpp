//
// Created by akio on 2021/1/31.
//
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>> &adjacentPairs) {
        int n = adjacentPairs.size() + 1;
        unordered_set<int> st;
        unordered_map<int, vector<int>> m;
        for (auto a : adjacentPairs) {
            m[a[0]].push_back(a[1]);
            m[a[1]].push_back(a[0]);
        }
        vector<int> res;
        int start;
        for (auto &p : m) {
            if (p.second.size() == 1) {
                start = p.first;
                // st.insert(start);
                // res.push_back(start);
                break;
            }
        }
        dfs(m, st, start, n, res);
        return res;
    }

private:
    bool dfs(unordered_map<int, vector<int>> &m, unordered_set<int> &st, int &uv, int &n, vector<int> &res) {
        res.push_back(uv);
        st.insert(uv);
        if (res.size() == n) return true;
        for (auto adj:m[uv]) {
            if (st.find(adj)==st.end()) {
                if (dfs(m, st, adj, n, res)) return true;
            }
        }
        res.pop_back();
        st.erase(uv);
        return false;
    }
};

int main() {
    vector<vector<int>> v{
            {4,  -10},
            {-1, 3},
            {4,  -3},
            {-3, 3}
    };
    Solution s;
    auto j = s.restoreArray(v);
    for (int i:j) {
        cout << i << ' ';
    }
    cout << endl;

}