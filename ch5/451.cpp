//
// Created by akio on 2020/10/17.
//
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        priority_queue<pair<int, char>> q;
        string res;
        for (auto c:s) ++m[c];
        for (auto p:m) q.push({p.second, p.first});
        while(!q.empty()){
            auto p = q.top();
            q.pop();
            for (int j = 0; j < p.first; ++j) {
                res += p.second;
            }
        }
        return res;
    }
};