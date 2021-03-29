#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int l = 0, n = s.size(), res = 0,r=0;
        unordered_set<char> st;
        while (l < n) {
            while (r < n && !st.count(s[r])) {
                st.insert(s[r++]);
            }
            res = max(res, r - l);
            while (s[l] != s[r]) {
                st.erase(s[l++]);
            }
            st.erase(s[l++]);
        }
        res = max(res, r - l);
        return res;
    }
};