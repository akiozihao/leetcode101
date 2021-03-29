#include <vector>
using namespace std;

class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] == m) {
                l = m + 1;
            } else
                r = m;
        }
        return r;
    }
};