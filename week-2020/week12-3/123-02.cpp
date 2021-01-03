//
// Created by akio on 2020/12/20.
//
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i = 0,j = 0;
        unordered_set<int> st;
        int res = 0,tmp = 0;
        while(i<nums.size()){
            while(!st.count(nums[j])){
                tmp += nums[j];
                st.insert(nums[j]);
                ++j;
            }
            res = max(res,tmp);
            while(nums[i]!=nums[j]){
                tmp -= nums[i];
                st.erase(nums[i]);
                ++i;
            }
            ++i;
        }
        return res;
    }
};