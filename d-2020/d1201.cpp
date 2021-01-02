#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1,-1};
        int lower = findFirst(nums,target);
        int upper =  findLast(nums,target);
        return {lower,upper};
    }

private:
    int findFirst(vector<int> &nums,int target){
        int l = 0,r = nums.size()-1;
        while(l<r){
            int mid = l + (r-l)/2;
            if(nums[mid]>=target)
                r = mid;
            else l = mid + 1;
        }
        if (nums[l] == target && (l == 0 || nums[l - 1] < target)) return l;

        return -1;
    }
    int findLast(vector<int> &nums,int target){
        int l =0,r = nums.size()-1;
        while(l<r){
            int mid = l + (r-l+1)/2;
            if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid;
        }
        if (nums[l] == target && (l == nums.size()-1 || nums[l + 1] > target)) return l;
        return -1;
    }
};


int main() {
    Solution s;
    vector<int> n{5,7,7,8,8,10};
    s.searchRange(n,6);
}