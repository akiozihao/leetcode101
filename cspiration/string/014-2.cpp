//
// Created by akio on 2021/2/18.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) return "";
        int minLength = min_element(strs.begin(), strs.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        })->size();
        int l = 0, r = minLength;
        while (l < r) {
            // 有边界 收缩到 m-1 时 求 m 要多加 1, 防止死循环
            int m = l + (r - l + 1) / 2;
            if (isCommonPrefix(strs, m)) l = m;
            else r = m - 1;
        }
        return strs[0].substr(0, l);
    }

private:
    bool isCommonPrefix(vector<string> &strs, int len) {
        string str0 = strs[0].substr(0, len);
        int m = strs.size();
        for (int i = 1; i < m; ++i) {
            string str = strs[i];
            for (int j = 0; j < len; ++j) {
                if (str0[j] != str[j]) {
                    return false;
                }
            }
        }
        return true;
    }
};