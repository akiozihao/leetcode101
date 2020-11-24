//
// Created by akio on 2020/10/16.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int l = 0, r = nums.size() - 1;
        while (true) {
            int pos = partition(nums, l, r);
            if (pos == k - 1) return nums[pos];
            if (pos > k - 1) r = pos - 1;
            else l = pos + 1;
        }
    }

private:
    int partition(vector<int> &nums, int left, int right) {
        int pivot = nums[left], l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l++], nums[r--]);
            }
            if (nums[l] >= pivot) ++l;
            if (nums[r] <= pivot) --r;
        }
        swap(nums[left], nums[r]);
        return r;
    }
};

int main() {
    Solution s;
    vector<int> a = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << s.findKthLargest(a, 4);
}

