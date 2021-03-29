#include <vector>
using namespace std;
class Solution {
   public:
    bool isStraight(vector<int>& nums) {
        int joker = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == 0)
                ++joker;
            else if (nums[i] == nums[i + 1])
                return false;
        }
        return nums.back() - nums[joker] < 5;
    }
};