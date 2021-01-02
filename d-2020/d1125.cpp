//
// Created by akio on 2020/11/25.
//
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string sortString(string s) {
        if (s.empty()) return s;
        vector<int> cnt(26, 0);
        int total = 0;
        for (const char &ch:s) {
            ++total;
            ++cnt[ch - 'a'];
        }
        string res;
        while (total) {
            for (int i = 0; i < 26; ++i) {
                if (cnt[i]) {
                    res.push_back('a' + i);
                    --cnt[i];
                    --total;
                }
            }
            for (int i = 25; i >= 0; --i) {
                if (cnt[i]) {
                    res.push_back('a' + i);
                    --cnt[i];
                    --total;
                }
            }
        }
        return res;
    }
};