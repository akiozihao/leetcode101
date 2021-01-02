//
// Created by akio on 2020/11/5.
//
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        vector<vector<string>> res;
        unordered_set<string> wordDict{wordList.begin(), wordList.end()};
        if (!wordDict.count(endWord)) return {};
        queue<vector<string>> paths;
        vector<string> p{beginWord};
        paths.push(p);
        unordered_set<string> usedWord;
        int level = 1, minLevel = INT_MAX;
        while (!paths.empty()) {
            vector<string> path = paths.front();
            paths.pop();
            if (path.size() > level) {
                for (const string &s:usedWord)
                    wordDict.erase(s);
                usedWord.clear();
                level = path.size();
                if (level > minLevel) break;
            }
            string last = path.back();
            for (int i = 0; i < last.size(); ++i) {
                string newLast = last;
                for (char c = 'a'; c <= 'z'; ++c) {
                    newLast[i] = c;
                    if (!wordDict.count(newLast)) continue;
                    usedWord.insert(newLast);
                    vector<string> nextPath = path;
                    nextPath.push_back(newLast);
                    if (newLast == endWord) {
                        res.push_back(nextPath);
                        minLevel = level;
                    } else paths.push(nextPath);
                }
            }
        }
        return res;
    }
};