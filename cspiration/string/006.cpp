//
// Created by akio on 2021/2/20.
//
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> v(numRows);
        int n = s.size(), dir = 1, cur = 0;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            v[cur].push_back(c);
            cur += dir;
            if (cur == numRows - 1 || cur == 0) dir *= -1;
        }
        string res;
        for (int i = 0; i < numRows; ++i) {
            string t(v[i].begin(), v[i].end());
            res += t;
        }
        return res;
    }
};