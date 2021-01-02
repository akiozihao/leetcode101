//
// Created by akio on 2020/12/20.
//
#include <string>
#include <list>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        list<char> stk;
        unordered_set<char> have;
        vector<int> cnt(26, 0);

        for (const char &ch:s) {
            ++cnt[ch - 'a'];
        }
        for (const char &ch:s) {
            --cnt[ch - 'a'];
            if (have.count(ch))
                continue;
            while (!stk.empty() && ch < stk.back() && cnt[stk.back() - 'a'] > 0) {
                auto tmp = stk.back();
                stk.pop_back();
                have.erase(tmp);
            }
            stk.push_back(ch);
            have.insert(ch);
        }
        return {stk.begin(), stk.end()};
    }
};