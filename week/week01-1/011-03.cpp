//
// Created by akio on 2021/1/3.
//
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;
typedef long long int64;

class Solution {
public:
    int waysToSplit(vector<int> &nums) {
        if (nums.empty() || nums.size() < 3) return 0;
        int res = 0;
        int n = nums.size();
        vector<int> pre(n + 1);
        for (int i = 0; i < pre.size(); ++i) {
            pre[i + 1] = pre[i] + nums[i];
        }
        // X,Y
        // pre[X] <= pre[Y] - pre[X] << pre[n] - pre[Y];
        // 2*pre[Y] <= pre[n] + pre[X];
        for (int X = 1; X + 2 <= n; ++X) {
            int Y1 = lower_bound(pre.begin(), pre.end(), 2 * pre[X]) - pre.begin();
            int Y2 = upper_bound(pre.begin(), pre.end(), (pre[n] + pre[X]) / 2) - pre.begin();
            Y1 = max(Y1, X + 1);
            Y2 = min(n, Y2);
            res += max(0, Y2 - Y1);
            if (res >= MOD) res -= MOD;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> a{1, 1, 1};
    s.waysToSplit(a);
}