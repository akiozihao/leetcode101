//
// Created by akio on 2021/1/21.
//
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int res = 0, i = 0, n = s.size(), j=0;
        unordered_set<int> st;
        while (i < n) {
            while (j < n && !st.count(s[j])) {
                st.insert(s[j++]);
            }
            res = max(res, j - i);
            while (s[i] != s[j]) {
                st.erase(st.find(s[i++]));
            }
            st.erase(s[i++]);
        }
        res = max(res, j - i);
        return res;
    }
};
};