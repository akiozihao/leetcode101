//
// Created by akio on 2021/1/10.
//
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        if (nums.empty()) return {};
        vector<string> res;
        int start = nums[0];
        int end = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != end + 1) {
                if (start == end) {
                    res.push_back(to_string(start));
                } else {
                    res.push_back(to_string(start) + "->" + to_string(end));
                }
                start = nums[i];
                end = nums[i];
            } else {
                end = nums[i];
            }
        }
        if (start == end) {
            res.push_back(to_string(start));
        } else {
            res.push_back(to_string(start) + "->" + to_string(end));
        }
        return res;
    }
};