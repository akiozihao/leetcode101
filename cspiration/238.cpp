//
// Created by akio on 2021/2/16.
//
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,1);
        int cur = 1;
        for(int i=1;i<n;++i){
            cur *= nums[i-1];
            res[i] = cur;
        }
        cur = 1;
        for(int i=n-2;i>=0;--i){
            cur *= nums[i+1];
            res[i] *= cur;
        }
        return res;
    }
};