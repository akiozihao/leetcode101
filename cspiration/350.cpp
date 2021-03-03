//
// Created by akio on 2021/2/17.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> m;
        for (auto n:nums1) {
            ++m[n];
        }
        vector<int> res;
        for (auto n:nums2) {
            if (m.count(n)) {
                res.push_back(n);
                --m[n];
                if (m[n] == 0) m.erase(n);
            }
        }
        return res;
    }

    vector<int> intersect2(vector<int> &nums1, vector<int> &nums2) {
        vector<int> res;
        int i = 0, j = 0;
        sort(nums1.begin(), nums2.end());
        sort(nums2.begin(), nums2.end());
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                ++i;
                ++j;
            } else if (nums1[i] < nums2[j]) {
                ++i;
            } else ++j;
        }
        return res;
    }

};