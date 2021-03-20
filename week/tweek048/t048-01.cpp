#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int secondHighest(string s) {
        set<int> st;
        for (char c : s) {
            if ('0' <= c && c <= '9') st.insert(c - '0');
        }
        if (st.size() < 2) return -1;
        return *prev(prev(st.end()));
    }
    int secondHighest2(string s) {
        int m1 = -1, m2 = -1;
        for (auto c : s) {
            if (c <= '9' && c >= '0') {
                int t = c - '0';
                if (t > m1) {
                    m2 = m1;
                    m1 = t;
                } else if (t < m1 && t > m2) {
                    m2 = t;
                }
            }
        }
        return m2;
    }
};