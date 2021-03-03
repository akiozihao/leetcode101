//
// Created by akio on 2021/2/8.
//
#include <bits/stdc++.h>

using namespace std;
// 归并排序
class Solution {
public:
    int countRangeSum(vector<int> &nums, int lower, int upper) {
        vector<long> sum(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); ++i) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        return countRangeSumRecursive(sum, lower, upper, 0, sum.size() - 1);
    }

private:
    int countRangeSumRecursive(vector<long> &sum, int lower, int upper, int left, int right) {
        if (left == right) {
            return 0;
        }
        int mid = left + (right - left) / 2;
        int n1 = countRangeSumRecursive(sum, lower, upper, left, mid);
        int n2 = countRangeSumRecursive(sum, lower, upper, mid + 1, right);
        int res = n1 + n2;

        int i = left, l = mid + 1, r = mid + 1;
        while (i <= mid) {
            while (l <= right && sum[l] - sum[i] < lower) ++l;
            while (r <= right && sum[r] - sum[i] <= upper) ++r;
            res += (r - l);
            ++i;
        }
        vector<int> sorted(right - left + 1);
        int p1 = left, p2 = mid + 1;
        int p = 0;
        while (p1 <= mid || p2 <= right) {
            if (p1 > mid) {
                sorted[p++] = sum[p2++];
            } else if (p2 > right) {
                sorted[p++] = sum[p1++];
            } else {
                if (sum[p1] < sum[p2]) {
                    sorted[p++] = sum[p1++];
                } else {
                    sorted[p++] = sum[p2++];
                }
            }
        }
        for (int i = 0; i < sorted.size(); ++i) {
            sum[left + i] = sorted[i];
        }
        return res;
    }
};