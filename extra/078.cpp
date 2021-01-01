//
// Created by akio on 2021/1/1.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> vec;
        helper(nums, res, vec, 0);
        return res;
    }

private:
    void helper(vector<int> &nums, vector<vector<int>> &res, vector<int> &vec, int idx) {
        res.push_back(vec);
        for(int i=idx;i<nums.size();++i){
            vec.push_back(nums[i]);
            helper(nums,res,vec,i+1);
            vec.pop_back();
        }
    }
};