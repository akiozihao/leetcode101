//
// Created by akio on 2021/2/18.
//
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) return 0;
        int n = s.size(), j = n - 1, i;
        while (j >= 0 && s[j] == ' ') {
            --j;
        }
        i = j;
        while (i >= 0 && s[i] != ' ') {
            --i;
        }
        return j - i;
    }
};