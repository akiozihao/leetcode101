//
// Created by akio on 2021/2/10.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if (m > n) return false;
        vector<int> cnt1(26, 0), cnt2(26, 0);
        for (int i = 0; i < m; ++i) {
            ++cnt1[s1[i] - 'a'];
            ++cnt2[s2[i] - 'a'];
        }
        if (cnt1 == cnt2) return true;
        for (int i = m; i < n; ++i) {
            ++cnt2[s2[i] - 'a'];
            --cnt2[s2[i - m] - 'a'];
            if (cnt1 == cnt2) return true;
        }
        return false;
    }

    bool checkInclusion2(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if (m > n) return false;
        vector<int> cnt(26, 0);
        for (int i = 0; i < m; ++i) {
            --cnt[s1[i] - 'a'];
        }
        int left = 0;
        for (int right = 0; right < m; ++right) {
            int x = s2[right] - 'a';
            ++cnt[x];
            while (cnt[x] > 0) {
                --cnt[s2[left] - 'a'];
                ++left;
            }
            if (right - left + 1 == m) return true;
        }
        return false;
    }
};