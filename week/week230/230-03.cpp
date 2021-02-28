#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int l1 = m, r1 = 6 * m, l2 = n, r2 = 6 * n;
        if (r1 < l2 || l1 > r2) return -1;
        int res = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int diff = accumulate(nums1.begin(), nums1.end(), 0) -
                   accumulate(nums2.begin(), nums2.end(), 0);
        if (diff == 0) return res;
        if (diff < 0) {
            int p1 = 0, p2 = n - 1;
            while (diff < 0) {
                ++res;
                if (p1 > m - 1) {
                    diff += nums2[p2--] - 1;
                } else if (p2 < 0) {
                    diff += (6 - nums1[p1++]);
                } else if (6 - nums1[p1] > nums2[p2] - 1) {
                    diff += 6 - nums1[p1++];
                } else
                    diff += nums2[p2--] - 1;
            }
            return res;
        } else {
            int p1 = m - 1, p2 = 0;
            while (diff > 0) {
                ++res;
                if (p1 < 0) {
                    diff -= 6 - nums2[p2++];
                } else if (p2 > n - 1) {
                    diff -= nums1[p1--] - 1;
                } else if (nums1[p1] - 1 > 6 - nums2[p2]) {
                    diff -= nums1[p1--] - 1;
                } else
                    diff -= 6 - nums2[p2++];
            }

            return res;
        }
        return diff;
    }
};

int main() {
    vector<int> v1{6, 6};
    vector<int> v2{1};
    Solution s;
    cout << s.minOperations(v1, v2);
}