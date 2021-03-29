#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    string reverseLeftWords(string s, int n) {
        int sz = s.size();
        n = n % sz;
        string res;
        res += string(s.begin() + n  +1, s.end());
        res += string(s.begin(),s.begin()+n);
        return res;
    }
};