//
// Created by akio on 2020/11/15.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minOperations(vector<int> &nums, int x) {
        if (x == 0) return 0;
        if (nums.empty()) return -1;
        int sz = (int) nums.size();
        vector<vector<int>> memo(sz, vector<int>(sz, -2));

        int res = helper(nums, 0, nums.size() - 1, x, memo);
        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < sz; ++j) {
                cout << memo[i][j] << ' ';
            }
            cout << endl;
        }
        return res;
    }

private:
    int helper(const vector<int> &nums, int first, int last, int x, vector<vector<int>> &memo) {
        if (memo[first][last] != -2) return memo[first][last];
        if (x == 0) {
            memo[first][last] = 0;
            return 0;
        }
        if (first > last || (nums[first] > x && nums[last] > x)) return -1;
        int c1 = -1, c2 = -1;
        if (x >= nums[first])
            c1 = helper(nums, first + 1, last, x - nums[first], memo);
        if (x >= nums[last])
            c2 = helper(nums, first, last, x - nums[last], memo);
        if (c1 == -1 && c2 == -1) {
            memo[first][last] = -1;
        } else if (c1 != -1 && c2 != -1) {
            memo[first][last] = min(c1, c2) + 1;
        } else {
            memo[first][last] = (c1 == -1 ? c2 + 1 : c1 + 1);
        }
        return memo[first][last];
    }
};

int main() {
    Solution s;
    vector<int> a{1, 1, 4, 2, 3};
    cout << s.minOperations(a, 5);
}