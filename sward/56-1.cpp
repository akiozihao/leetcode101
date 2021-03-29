#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> singleNumbers(vector<int>& nums) {
        int k = 0;
        for (const auto& n : nums) {
            k ^= n;
        }
        int t = 1;
        while ((t & k) == 0) {
            t <<= 1;
        }
        int a = 0, b = 0;
        for (const auto& n : nums) {
            if (t & n) {
                a ^= n;
            } else
                b ^= n;
        }
        return {a, b};
    }
};