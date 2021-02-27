#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string rearrangeString(string str, int k) {
        if (k == 0) return str;
        string res;
        int len = (int)str.size();
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> m;
        for (const char &c : str) {
            ++m[c];
        }
        for (auto it = m.begin(); it != m.end(); ++it) {
            pq.push({it->first, it->second});
        }
        while (!pq.empty()) {
            vector<pair<int, int>> v;
            int cnt = min(k, len);
            for (int i = 0; i < cnt; ++i) {
                if (pq.empty()) return "";
                auto t = pq.top();
                pq.pop();
                res.push_back(t.second);
                if (--t.first > 0) v.push_back(t);
                --len;
            }
            for (auto a : v) pq.push(a);
        }
        return res;
    }
};