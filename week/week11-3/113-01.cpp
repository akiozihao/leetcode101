//
// Created by akio on 2020/11/22.
//
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2) {
        if (word1.empty() && word2.empty()) return true;
        if (word1.empty() || word2.empty()) return false;
        string a, b;
        for (const auto &w1:word1) {
            a += w1;
        }
        for (const auto &w2:word2) {
            b += w2;
        }
        return a == b;
    }
};