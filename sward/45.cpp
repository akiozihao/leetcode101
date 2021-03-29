#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string minNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end(), [](const int &a, const int &b) {
            return to_string(a) + to_string(b) < to_string(b) + to_string(a);
        });
        string res;
        for (auto x : nums) {
            res += to_string(x);
        }
        return res;
    }
};