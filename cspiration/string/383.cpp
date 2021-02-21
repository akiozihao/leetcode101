//
// Created by akio on 2021/2/18.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.empty()) return true;
        int m = ransomNote.size(), n = magazine.size();
        if (m > n) return false;
        vector<int> cnt(26, 0);
        for (auto &c:magazine) {
            ++cnt[c - 'a'];
        }
        for (auto &c:ransomNote) {
            if (cnt[c - 'a']-- == 0) return false;
        }
        return true;
    }
};