//
// Created by akio on 2021/1/21.
//
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        if (s.empty()) return 0;
        vector<int> counts;
        int cnt = 1;
        char prev = s[0];
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] != prev) {
                counts.push_back(cnt);
                cnt = 1;
                prev = s[i];
            }else{
                ++cnt;
            }
        }
        counts.push_back(cnt);
        int res = 0;
        for (int i = 1; i < counts.size(); ++i) {
            res += min(counts[i - 1], counts[i]);
        }
        return res;
    }
};