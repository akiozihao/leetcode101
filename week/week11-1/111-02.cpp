//
// Created by akio on 2020/11/8.
//
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        if (s.empty()) return 0;
        multiset<int> mst;
        unordered_map<char, int> m;
        for (char ch:s) {
            ++m[ch];
        }
        int mx = 0;
        for (auto p:m) {
            mx = max(p.second, mx);
            mst.insert(p.second);
        }
        vector<bool> flag(mx + 1, false);
        int res = 0;
        for (auto p = mst.rbegin(); p != mst.rend(); ++p) {
            if (!flag[*p])
                flag[*p] = true;
            else {
                int idx = *p - 1;
                while (idx >= 0) {
                    if (!flag[idx]) break;
                    --idx;
                }
                if(idx < 0) res += *p;
                else{
                    flag[idx] = true;
                    res += *p - idx;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.minDeletions("bbcebab");
}