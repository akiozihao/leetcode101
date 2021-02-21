//
// Created by akio on 2021/2/18.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        if (s.empty()) return -1;
        vector<int> cnt(26, 0);
        for (auto c:s) {
            ++cnt[c - 'a'];
        }
        for (int i = 0; i < s.size(); ++i) {
            if (cnt[s[i]-'a'] == 1) return i;
        }
        return -1;
    }
};