//
// Created by akio on 2020/10/13.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        if (nums.empty()) return {-1, -1};
        int lower = lower_bound(nums, target);
        int upper = upper_bound(nums, target);
        if (lower == nums.size() || nums[lower] != target)
            return {-1, -1};
        return {lower, upper};
    }

private:
    int lower_bound(const vector<int> &nums, int target) {
        int l = 0, r = nums.size(), mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (nums[mid] >= target)
                r = mid;
            else l = mid + 1;
        }
        return l;
    }

    int upper_bound(const vector<int> &nums, int target) {
        int l = 0, r = nums.size(), mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (nums[mid] > target)
                r = mid;
            else
                l = mid + 1;
        }
        return l-1;
    }


};

