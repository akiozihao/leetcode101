//
// Created by akio on 2021/2/2.
//
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(26);
        int n = s.size(), maxn = 0, left = 0, right = 0, res = 0;
        while (right < n) {
            ++cnt[s[right] - 'A'];
            maxn = max(maxn, cnt[s[right++] - 'A']);
            if (right - left - maxn > k) {
                --cnt[s[left++] - 'A'];
            }
            res = max(res, right - left);
        }
        return res;
    }
};