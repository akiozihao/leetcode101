//
// Created by akio on 2021/1/31.
//
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;
const int N = 200016;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>> &adjacentPairs) {
        vector<int> res;
        unordered_set<int> st;
        unordered_map<int, vector<int>> m;
        int n = adjacentPairs.size() + 1;
        for (auto a:adjacentPairs) {
            m[a[0]].push_back(a[1]);
            m[a[1]].push_back(a[0]);
        }
        int start;
        for (auto &p : m) {
            if (p.second.size() == 1) {
                start = p.first;
                st.insert(start);
                res.push_back(start);
                break;
            }
        }

        int cur = start;
        while (st.size() < n) {
            for (int i = 0; i < m[cur].size(); ++i) {
                if (st.find(m[cur][i]) == st.end()) {
                    cur = m[cur][i];
                    st.insert(cur);
                    res.push_back(cur);
                    break;
                }
            }
        }
        return res;
    }
};