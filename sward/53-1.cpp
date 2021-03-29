#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        auto ptr1 = lower_bound(nums.begin(), nums.end(), target);
        auto ptr2 = upper_bound(nums.begin(), nums.end(), target);
        return distance(ptr1, --ptr2);
    }
};