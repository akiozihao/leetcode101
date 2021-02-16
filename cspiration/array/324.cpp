//
// Created by akio on 2021/2/16.
//
#include <vector>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        vector<int> tmp = nums;
        int n = nums.size(), k = (n + 1) / 2, j = n;
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i < n; ++i) {
            nums[i] = i & 1 ? tmp[--j] : tmp[--k];
        }
    }

    void wiggleSort2(vector<int> &nums) {
        auto midptr = nums.begin() + nums.size() / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;

        // 3-way-partition
        int i = 0, j = 0, k = nums.size() - 1;
        while (j < k) {
            if (nums[j] > mid) {
                swap(nums[j], nums[k]);
                --k;
            } else if (nums[j] < mid) {
                swap(nums[i], nums[j]);
                ++i;
                ++j;
            } else ++j;
        }
        if (nums.size() % 2) ++midptr;
        vector<int> tmp1(nums.begin(), midptr);
        vector<int> tmp2(midptr, nums.end());
        for (int i = 0; i < tmp1.size(); ++i) {
            nums[2 * i] = tmp1[tmp1.size() - 1 - i];
        }
        for (int i = 0; i < tmp2.size(); ++i) {
            nums[2 * i + 1] = tmp2[tmp2.size() - 1 - i];
        }
    }

};