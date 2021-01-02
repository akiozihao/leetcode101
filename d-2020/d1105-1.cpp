//
// Created by akio on 2020/11/5.
//
#include <string>
#include <unordered_set>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        unordered_set<string> st{wordList.begin(), wordList.end()};
        if (!st.count(endWord)) return 0;
        unordered_map<string, int> pathCnt({{beginWord, 1}});
        queue<string> q({beginWord});
        while (!q.empty()) {
            string word = q.front();
            q.pop();
            for (int i = 0; i < word.size(); ++i) {
                string newWord = word;
                for (char c = 'a'; c <= 'z'; ++c) {
                    newWord[i] = c;
                    if (st.count(newWord) && newWord == endWord) return pathCnt[word] + 1;
                    if (st.count(newWord) && !pathCnt.count(newWord)) {
                        q.push(newWord);
                        pathCnt[newWord] = pathCnt[word] + 1;
                    }
                }
            }
        }
        return 0;
    }
};