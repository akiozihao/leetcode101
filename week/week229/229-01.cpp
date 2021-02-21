//
// Created by akio on 2021/2/21.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        if (m == 0 || n == 0) {
            if (m == 0) return word2;
            else return word1;
        }
        string res;
        int p1 = 0, p2 = 0;
        while (p1 < m && p2 < n) {
            if (p1 <= p2) {
                res += word1[p1++];
            } else res += word2[p2++];
        }
        while (p1 < m) {
            res += word1[p1++];
        }
        while (p2 < n) {
            res += word2[p2++];
        }
        return res;
    }
};