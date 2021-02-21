//
// Created by akio on 2021/2/20.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestNiceSubstring(string s) {
        int ml = -1, mlen = -1;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < s.size(); ++j) {
                unordered_set<char> st(s.begin() + i, s.begin() + j + 1);
                bool flag = false;
                for (auto c:st) {
                    if (c <= 'Z' && !st.count(c + 32)) break;
                    if (c >= 'a' && !st.count(c - 32)) break;
                }
                if (j - i + 1 > mlen) {
                    ml = i;
                    mlen = j - i + 1;
                }
            }
        }
        return ml == -1 ? "" : s.substr(ml, mlen);
    }
};