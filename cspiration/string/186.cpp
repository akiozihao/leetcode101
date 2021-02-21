//
// Created by akio on 2021/2/18.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void reverseWords(vector<char> &str) {
        reverse(str.begin(), str.end());
        for (int i = 0, j; i < str.size(); i = j + 1) {
            for (j = i; j < str.size(); ++j) {
                if (str[j] == ',') break;
            }
            reverse(str.begin() + i, str.begin() + j);
        }
    }
};