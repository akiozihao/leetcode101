#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int shipWithinDays(vector<int>& weights, int D) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0) + 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (day(weights, mid) > D) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

   private:
    int day(const vector<int>& weights, int d) {
        int res = 0, cur = 0;
        for (int w : weights) {
            cur += w;
            if (cur > d) {
                ++res;
                cur = w;
            }
        }
        return res;
    }
};