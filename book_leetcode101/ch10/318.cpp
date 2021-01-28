//
// Created by akio on 2021/1/11.
//
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string> &words) {
        if (words.empty() || words.size() < 2) return 0;
        int n = words.size();
        vector<int> cnt(n, 0);
        for (int i = 0; i < n; ++i) {
            string &w = words[i];
            for (auto &c:w) {
                cnt[i] |= 1 << (c - 'a');
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if ((cnt[i] & cnt[j]) == 0) {
                    res = max(res, (int) words[i].size() * (int) words[j].size());
                }
            }
        }
        return res;
    }
};