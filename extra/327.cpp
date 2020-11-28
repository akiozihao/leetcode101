//
// Created by akio on 2020/11/28.
//
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int countRangeSum(vector<int> &nums, int lower, int upper) {
        if (nums.empty()) return 0;
        int res = 0;
        long long sum = 0;
        multiset<long long> mst;
        mst.insert(0);
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            res += distance(mst.lower_bound(sum - upper), mst.upper_bound(sum - lower));
            mst.insert(sum);
        }
        return res;
    }
};