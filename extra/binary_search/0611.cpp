//
// Created by akio on 2021/1/1.
//
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int> &nums) {
        if (nums.empty() || nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int sum = nums[i] + nums[j], left = j + 1, right = n;
                while (left < right) {
                    int mid = left + (right - left) / 2;
                    if (nums[mid] < sum) {
                        left = mid + 1;
                        cout << "left:" << left << endl;
                    }
                    else {
                        right = mid;
                        cout << "right:" << right << endl;
                    }
                }
                res += right - j - 1;
            }
        }
        return res;
    }
};