//
// Created by akio on 2020/10/15.
//
#include <vector>

using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int total = nums1.size() + nums2.size();
        if (total % 2 == 1) {
            return getKthElement(nums1, nums2, (total + 1) / 2);
        } else
            return 0.5 * (getKthElement(nums1, nums2, total / 2) + getKthElement(nums1, nums2, total / 2 + 1));
    }

private:
    int getKthElement(const vector<int> &nums1, const vector<int> &nums2, int k) {
        int m = nums1.size(), n = nums2.size(), idx1 = 0, idx2 = 0;
        while (true) {
            if (idx1 == m) return nums2[idx2 + k - 1];
            if (idx2 == n) return nums1[idx1 + k - 1];
            if (k == 1) return min(nums1[idx1], nums2[idx2]);

            int newIdx1 = min(idx1 + k / 2 - 1, m - 1);
            int newIdx2 = min(idx2 + k / 2 - 1, n - 1);
            int pivot1 = nums1[newIdx1];
            int pivot2 = nums2[newIdx2];
            if (pivot1 <= pivot2) {
                k -= newIdx1 - idx1 + 1;
                idx1 = newIdx1 + 1;
            } else {
                k -= newIdx2 - idx2 + 1;
                idx2 = newIdx2 + 1;
            }
        }
    }
};