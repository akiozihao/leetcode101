//
// Created by akio on 2021/2/5.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string largestMerge(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> mem(m + 1, vector<int>(n + 1, 0));
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (word1[i] > word2[j]) mem[i][j] = 1;
                else if (word1[i] < word2[j]) mem[i][j] = -1;
                else {
                    mem[i][j] = mem[i + 1][j + 1];
                }
            }
        }
        int i = 0, j = 0;
        string res;
        while (i < m && j < n) {
            if (mem[i][j] == 1) {
                res += word1[i++];
            } else if (mem[i][j] == -1) {
                res += word2[j++];
            } else {
                res += word2[j++];
                res += word1[i++];
            }
        }
        if (i < m) {
            res += word1.substr(i);
        }
        if (j < n) {
            res += word2.substr(j);
        }
        return res;
    }

    string largestMerge2(string word1, string word2) {
        string res;
        int i = 0, j = 0;
        while (i < word1.size() && j < word2.size()) {
            if (word1.substr(i) > word2.substr(j)) {
                res += word1[i];
                ++i;
            } else {
                res += word2[j];
                ++j;
            }
        }
        if (i < word1.size()) {
            res += word1.substr(i);
        }
        if (j < word2.size()) {
            res += word2.substr(j);
        }
        return res;
    }

};