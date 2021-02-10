//
// Created by akio on 2021/2/8.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> res(k, 0);
        int start = max(0, k - n), end = min(k, m);
        for (int i = start; i <= end; ++i) {
            vector<int> subSeq1(MaxSub(nums1, i));
            vector<int> subSeq2(MaxSub(nums2, k - i));
            vector<int> curMaxSub(merge(subSeq1, subSeq2));
            if (compare(curMaxSub, 0, res, 0) > 0) {
                res.swap(curMaxSub);
            }
        }
        return res;
    }

private:
    vector<int> MaxSub(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> st(k, 0);
        int top = -1;
        int remain = n - k;
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            while (top >= 0 && st[top] < num && remain > 0) {
                top--;
                remain--;
            }
            if (top < k - 1) {
                st[++top] = num;
            } else {
                remain--;
            }
        }
        return st;
    }

    vector<int> merge(vector<int> &v1, vector<int> &v2) {
        int m = v1.size(), n = v2.size();
        if (m == 0) return v2;
        if (n == 0) return v1;
        int t = m + n;
        vector<int> res(t);
        int p1 = 0, p2 = 0;
        for (int i = 0; i < t; ++i) {
            if (compare(v1, p1, v2, p2) > 0) {
                res[i] = v1[p1++];
            } else {
                res[i] = v2[p2++];
            }
        }
        return res;
    }

    int compare(vector<int> &v1, int i, vector<int> &v2, int j) {
        int m = v1.size(), n = v2.size();
        while (i < m && j < n) {
            int diff = v1[i] - v2[j];
            if (diff) return diff;
            ++i;
            ++j;
        }
        return i < m ? 1 : -1;
    }
};