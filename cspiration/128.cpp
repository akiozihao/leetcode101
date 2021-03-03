//
// Created by akio on 2021/2/5.
//

#include<bits//stdc++.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> st{nums.begin(), nums.end()};
        int res = 0;
        for (auto &n:nums) {
            if (!st.count(n)) continue;
            st.erase(n);
            int l = n - 1, r = n + 1;
            while (st.count(l)) {
                st.erase(l--);
            }
            while(st.count(r)){
                st.erase(r++);
            }
            res = max(res,r-l-1);
        }
        return res;
    }
};