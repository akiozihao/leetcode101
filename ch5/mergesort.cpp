//
// Created by akio on 2020/10/16.
//

#include <vector>

using namespace std;

void merge_sort(vector<int> &nums, int l, int r, vector<int> &temp) {
    if (l > r)
        return;
    int m = l + (r - l) / 2;
    merge_sort(nums, l, m, temp);
    merge_sort(nums, m + 1, r, temp);
    int p = l, q = m, i = l;
    while (p < m || q < r) {
        if (q >= r || (p < m && nums[p] <= nums[q]))
            temp[i++] = nums[p++];
        else
            temp[i++] = nums[q++];
    }
    for (i = l; i < r; ++i) {
        nums[i] = temp[i];
    }
}