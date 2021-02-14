//
// Created by akio on 2021/2/14.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countHomogenous(string s) {
        int mod = 1e9+7;
        vector<int> cnt(26,0);
        int left=0,right=0,n=s.size();
        int res = 0;
        while (right < n){
            while(s[right]==s[left]) ++right;
            long long c = right-left;
            res += (c * (c+1)/2) % mod;
            left = right;
        }
        long long c = right-left;
        res += (c * (c+1)/2) % mod;
        return res;
    }
};