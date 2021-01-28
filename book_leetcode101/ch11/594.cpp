//
// Created by akio on 2021/1/14.
//
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int findLHS(vector<int> &nums) {
        if (nums.empty()) return 0;
        map<int, int> m;
        for (int &i:nums) {
            ++m[i];
        }
        int res = 0;
        for (auto it = next(m.begin()); it != m.end(); ++it) {
            auto pre = prev(it);
            if (it->first == pre->first + 1) {
                res = max(res, it->second + pre->second);
            }
        }
        return res;
    }
};