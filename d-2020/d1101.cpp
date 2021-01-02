//
// Created by akio on 2020/11/1.
//
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        unordered_map<string, vector<string>> m;
        return helper(s, wordDict, m);
    }

private:
    vector<string> helper(const string &s, vector<string> &wordDict, unordered_map<string, vector<string>> &m) {
        if (m.count(s)) return m[s];
        if (s.empty()) return {""};
        vector<string> res;
        for (const string &word:wordDict) {
            if (s.substr(0, word.size()) != word) continue;
            vector<string> rem = helper(s.substr(word.size()), wordDict, m);
            for (const string &str:rem) {
                res.push_back(word + (str.empty() ? "" : " ") + str);
            }
        }
        return m[s] = res;
    }
};