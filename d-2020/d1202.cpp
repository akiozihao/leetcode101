//
// Created by akio on 2020/12/2.
//
#include <vector>
#include <stack>

using namespace std;
class Solution {
public:
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
        if (k == 0) return {};
        int m = nums1.size(), n = nums2.size();
        vector<int> res(k, 0);
        int start = max(0, k - n), end = min(m, k);
        for (int i = start; i <= end; ++i) {
            vector<int> sub1 = maxSub(nums1, i);
            vector<int> sub2 = maxSub(nums2, k - i);
            vector<int> t = merge(sub1, sub2);
            if (compare(t, 0,res,0) > 0)
                res.swap(t);
        }
        return res;
    }

private:
    vector<int> maxSub(vector<int> &nums, int k) {
        int sz = nums.size();
        vector<int> stack(k, 0);
        int top = -1;
        int remain = sz - k;
        for (int i = 0; i < sz; ++i) {
            int num = nums[i];
            while (top >= 0 && stack[top] < num && remain > 0) {
                --top;
                --remain;
            }
            if (top < k - 1)
                stack[++top] = num;
            else
                --remain;
        }
        return stack;
    }

    vector<int> merge(vector<int> &nums1, vector<int> &nums2) {
        int x = nums1.size(), y = nums2.size();
        if (x == 0)
            return nums2;
        if (y == 0)
            return nums1;
        int p1 = 0, p2 = 0;
        vector<int> res;
        while (p1 < x && p2 < y) {
            if (compare(nums1,p1,nums2,p2) > 0) {
                res.push_back(nums1[p1++]);
            } else {
                res.push_back(nums2[p2++]);
            }
        }
        while (p1 < x)
            res.push_back(nums1[p1++]);
        while (p2 < y)
            res.push_back(nums2[p2++]);
        return res;
    }

    int compare(vector<int> &nums1, int idx1, vector<int> &nums2, int idx2) {
        int x = nums1.size(), y = nums2.size();
        while (idx1 < x && idx2 < y) {
            int diff = nums1[idx1] - nums2[idx2];
            if (diff != 0)
                return diff;
            ++idx1;
            ++idx2;
        }
        return (x - idx1) - (y - idx2);
    }
};