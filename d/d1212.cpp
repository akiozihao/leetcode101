//
// Created by akio on 2020/12/12.
//
#include <vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.empty()) return 0;
        int sz = nums.size();
        if(sz < 2)
            return sz;
        vector<int> up(sz,1),down(sz,1);
        for(int i=1;i<sz;++i){
            if(nums[i]>nums[i-1]){
                up[i] = max(up[i-1],down[i-1] + 1);
                down[i] = down[i-1];
            }else if(nums[i] < nums[i-1]){
                down[i]= max(down[i-1],up[i-1] + 1);
                up[i] = up[i-1];
            }else{
                down[i] = down[i-1];
                up[i] = up[i-1];
            }
        }
        return max(up.back(),down.back());
    }
};