//
// Created by akio on 2021/2/9.

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end(),[](auto &a,auto &b){
           return a[0] < b[0];
        });
        int left = intervals[0][0],right = intervals[0][1],n=intervals.size();
        for(int i=1;i<n;++i){
            auto e = intervals[i];
            if(right < e[0]){
                res.push_back({left,right});
                left = e[0];
                right = e[1];
            }else{
                right = e[1];
            }
        }
        res.push_back({left,right});
        return res;
    }
};