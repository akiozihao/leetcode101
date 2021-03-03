//
// Created by akio on 2021/2/16.
//
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        if (nums.empty()) return 0;
        vector<int> dpmx(nums),dpmn(nums);
        for(int i=1;i<nums.size();++i){
            dpmx[i] = max(dpmx[i-1] * nums[i],max(dpmn[i-1]*nums[i],nums[i]));
            dpmn[i] = min(dpmn[i-1] * nums[i],min(dpmx[i-1]*nums[i],nums[i]));
        }
        return *max_element(dpmx.begin(),dpmx.end());
    }
};