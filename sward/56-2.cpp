#include <vector>
using namespace std;
class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        vector<int> cnt(32, 0);
        for (int n : nums) {
            for (int j = 0; j < 32; ++j) {
                cnt[j] += n & 1;
                n >>= 1;
            }
        }
        int res = 0;
        for (int i = 31; i >= 0; --i) {
            res <<= 1;
            res |= cnt[i] % 3;
        }
        return res;
    }
};