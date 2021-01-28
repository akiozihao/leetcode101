//
// Created by akio on 2020/10/25.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        vector<bool> visited(nums.size(), false);
        backtracking(nums, tmp, res, visited);
        return res;
    }

private:
    void backtracking(vector<int> &nums, vector<int> &tmp, vector<vector<int>> &res, vector<bool> &visited) {
        if (tmp.size() == nums.size()) {
            res.push_back(tmp);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i]) continue;
            visited[i] = true;
            tmp.push_back(nums[i]);
            backtracking(nums, tmp, res, visited);
            visited[i] = false;
            tmp.pop_back();
        }
    }
};