//
// Created by akio on 2020/10/13.
//
#include <string>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r])
                return help(s, l, r - 1) || help(s, l + 1, r);
            ++l;
            --r;
        }
        return true;
    }

private:
    bool help(const string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            ++l;
            --r;
        }
        return true;
    }
};