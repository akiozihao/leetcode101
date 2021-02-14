//
// Created by akio on 2021/2/14.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string a,b;
        a[0] = '0';
        b[0] = '1';
        for(int i=1;i<n;++i){
            a.push_back(a[i-1]=='0'?'1':'0');
            b.push_back(b[i-1]=='0'?'1':'0');
        }
        int cnt1=0,cnt2=0;
        for(int i=0;i<n;++i){
            if(s[i]!=a[i]) ++cnt1;
            if(s[i]!=b[i]) ++cnt2;
        }
        return min(cnt1,cnt2);
    }
};