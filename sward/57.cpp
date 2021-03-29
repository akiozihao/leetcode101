#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        vector<int> v;
        for (int l = 1, r = 2; l < r;) {
            int sum = (l + r) * (r-l + 1) / 2;
            if (sum == target) {
                v.clear();
                for (int i = l; i <= r; ++i) {
                    v.emplace_back(i);
                }
                res.emplace_back(v);
                ++l;
            } else if (sum < target) {
                ++r;
            } else {
                ++l;
            }
        }
        return res;
    }
};