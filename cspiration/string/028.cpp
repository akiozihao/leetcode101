//
// Created by akio on 2021/2/17.
//
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if (m < n) return -1;
        if (n == 0) return 0;
        for (int i = 0; i <= m - n; ++i) {
            if (haystack[i] == needle[0]) {
                int j = 1;
                while (j < n) {
                    if (haystack[i + j] == needle[j]) ++j;
                    else break;
                }
                if (j == n) return i;
            }
        }
        return -1;
    }
};