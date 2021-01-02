//
// Created by akio on 2021/1/2.
//
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size(),left = 0,right = nums.back()-nums[0];
        while(left < right){
            int mid = left + (right-left)/2,cnt=0,start=0;
            for(int i=0;i<n;++i){
                while(start<n && nums[i]-nums[start] > mid) ++start;
                cnt += i-start;
            }
            if(cnt<k) left = mid + 1;
            else right = mid;
        }
        return right;
    }
};