//
// Created by akio on 2020/10/14.
//
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int> &nums, int target) {
        if (nums.empty()) return false;
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return true;
            if (nums[l] == nums[mid]) ++l;
            else if (nums[mid] <= nums[r]) {
                if (target > nums[mid] && target <= nums[r])
                    l = mid + 1;
                else {
                    r = mid - 1;
                }
            } else {
                if (target >= nums[l] && target < nums[mid]) {
                    r = mid - 1;
                } else
                    l = mid + 1;
            }
        }
        return false;
    }
};