//
// Created by akio on 2021/2/20.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string> &strings) {
        unordered_map<string, multiset<string>> m;
        vector<vector<string>> res;
        for (auto a:strings) {
            string key;
            for (char c:a) {
                key += to_string((c + 26 - a[0]) % 26) + ',';
            }
            m[key].insert(a);
        }
        for (const auto &p:m) {
            res.emplace_back(p.second.begin(), p.second.end());
        }
        return res;
    }
};