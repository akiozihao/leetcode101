//
// Created by akio on 2021/2/5.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        if (s.empty()) return 0;
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) break;
            ++l, --r;
            while (l + 1 < r && s[l] == s[l + 1]) ++l;
            while (r - 1 > l && s[r] == s[r - 1]) --r;
        }
        return r - l + 1;
    }
};