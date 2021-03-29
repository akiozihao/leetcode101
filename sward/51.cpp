#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int reversePairs(vector<int> &nums) {
        int n = nums.size();
        vector<int> tmp(n);
        return mergeSort(nums, tmp, 0, n - 1);
    }

   private:
    int mergeSort(vector<int> &nums, vector<int> &tmp, int l, int r) {
        if (l >= r) return 0;
        int mid = l + (r - l) / 2;
        int inv_count =
            mergeSort(nums, tmp, l, mid) + mergeSort(nums, tmp, mid + 1, r);
        int i = l, j = mid + 1, pos = l;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[pos] = nums[i++];
                inv_count += (j - (mid + 1));
            } else {
                tmp[pos] = nums[j++];
            }
            ++pos;
        }
        for (int k = i; k <= mid; ++k) {
            tmp[pos++] = nums[k];
            inv_count += j - (mid + 1);
        }
        for (int k = j; k <= r; ++k) {
            tmp[pos++] = nums[k];
        }
        copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
        return inv_count;
    }
};