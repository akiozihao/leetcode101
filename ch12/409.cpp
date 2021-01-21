//
// Created by akio on 2021/1/21.
//
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        for (char &c:s) {
            ++m[c];
        }
        int res = 0;
        for (auto p:m) {
            int cnt = p.second;
            res += cnt / 2 * 2;
            if (cnt % 2 == 1 && res % 2 == 0) {
                ++res;
            }
        }
        return res;
    }
};