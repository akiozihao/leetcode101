//
// Created by akio on 2021/2/1.
//
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int> &nums) {
        if (nums.empty() || nums.size() < 3) return false;
        int t1 = INT_MAX;
        int t2 = INT_MAX;
//        int t3 = INT_MAX;
        for (auto &n:nums) {
            if (n <= t1) {
                t1 = n;
            } else if (n <= t2) {
                t2 = n;
            } else if (n > t2) return true;
        }
        return false;
    }
};