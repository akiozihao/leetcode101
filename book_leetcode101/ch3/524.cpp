//
// Created by akio on 2020/10/13.
//
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string> &d) {
        string res;
        for (auto &i : d) {
            if (helper(s, i)) {
                if (i.size() > res.size() || (i.size() == res.size() && i < res)) res = i;
            }
        }
        return res;
    }

private:
    bool helper(const string &s, const string &t) {
        int i = 0, j = 0;
        while (j < t.size() && i < s.size()) {
            if (s[i] == t[j])
                ++j;
            ++i;
        }
        return j == t.size();
    }
};