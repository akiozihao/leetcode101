//
// Created by akio on 2020/10/13.
//
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int res = 0, l = 0;
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); ++i) {
            ++m[s[i]];
            while (m.size() > k) {
                if(--m[s[l]]==0) m.erase(s[l]);
                ++l;
            }
            res = max(res,i-l+1);
        }
        return res;
    }
}