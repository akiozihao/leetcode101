//
// Created by akio on 2021/2/18.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_set<char> st{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    string reverseVowels(string s) {
        if (s.empty()) return s;
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < r  && !st.count(s[l])) ++l;
            while (l < r  && !st.count(s[r]))--r;
            if(l < r ) swap(s[l++], s[r--]);
        }
        return s;
    }
};