//
// Created by akio on 2021/2/14.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumSize(vector<int> &nums, int maxOperations) {
        int l = 1, r = *max_element(nums.begin(), nums.end())+1, n = nums.size(), mid, res;
        while (l < r) {
            int m = l + (r - l) / 2;
            if(check(nums,m,maxOperations)){
                r = m - 1;
                res = m;
            }else{
                l = m + 1;
            }
        }
        return res;
    }

private:
    bool check(vector<int> &nums,int cost,int maxOperations){
        long long res = 0;
        for(int cur:nums){
            if(cur %cost ==0){
                res += cur/ cost - 1;
            }else{
                res += cur/cost;
            }
        }
        return res <= maxOperations;
    }
};

int main() {
    Solution s;
    vector<int> n{2, 4, 8, 2};
    cout << s.minimumSize(n, 4);
}