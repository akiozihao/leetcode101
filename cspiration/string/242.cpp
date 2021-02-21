//
// Created by akio on 2021/2/20.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cnt(26, 0);
        for (auto &c:s) {
            ++cnt[c - 'a'];
        }
        for (auto &c:t) {
            if (--cnt[c - 'a'] < 0) return false;
        }
        return accumulate(cnt.begin(), cnt.end(), 0) == 0;
    }
};