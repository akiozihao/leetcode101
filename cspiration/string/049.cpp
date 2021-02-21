//
// Created by akio on 2021/2/20.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> m;
        for (auto &s:strs) {
            string key;
            vector<int> cnt(26, 0);
            for (auto &c:s) {
                ++cnt[c - 'a'];
            }
            for (int i = 0; i < 26; ++i) {
                key += to_string(cnt[i]);
            }
            m[key].push_back(s);
        }
        vector<vector<string>> res;
        for(auto &p:m){
            res.emplace_back(p.second);
        }
        return res;
    }
};