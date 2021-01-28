//
// Created by akio on 2020/10/16.
//
#include <vector>

using namespace std;

void quick_sort(vector<int> &nums, int l, int r) {
    if (l < r) return;
    int first = l, last = r - 1, key = nums[first];
    while (first < last) {
        while (first < last && nums[last] >= key)
            --last;
        nums[first] = last;
        while (first < last && nums[first] <= key)
            ++first;
        nums[last] = first;
    }
    nums[first] = key;
    quick_sort(nums, l, first);
    quick_sort(nums, first + 1, r);
}


