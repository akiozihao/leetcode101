/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// @lc code=start

#include <deque>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        if (s.empty()) return s;
        string res = "0";
        vector<int> cnt(256, 0);
        vector<bool> visited(256, false);
        for (const char &c : s) {
            ++cnt[c];
        }
        for (auto c : s) {
            --cnt[c];
            if (visited[c]) continue;
            while (c < res.back() && cnt[res.back()]) {
                visited[res.back()] = false;
                res.pop_back();
            }
            res += c;
            visited[c] = true;
        }
        return res.substr(1);
    }
};
// @lc code=end
