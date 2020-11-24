//
// Created by akio on 2020/11/22.
//
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.empty() && t.empty()) return true;
        if (s.empty() || t.empty()) return false;
        if (s.size() != t.size()) return false;
        int sz = s.size();
        vector<int> cnt(26, 0);
        for (const char &c:s) {
            ++cnt[c - 'a'];
        }
        for (const char &c:t) {
            --cnt[c - 'a'];
        }
        for (const int &i:cnt) {
            if (i) return false;
        }
        return true;
    }
};