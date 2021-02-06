//
// Created by akio on 2021/2/5.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumOfUnique(vector<int> &nums) {
        vector<int> cnt(101, 0);
        for (auto n:nums) {
            ++cnt[n];
        }
        int res = 0;
        for(int i=0;i<cnt.size();++i){
            if(cnt[i]==1){
                res += i;
            }
        }
        return res;
    }
};