//
// Created by akio on 2021/1/17.
//
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int> &nums) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i+1; j < nums.size(); ++j) {
                ++m[i * j];
            }
        }
        int res = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second > 1) {
                res += (it->second) * (it->second - 1) * 4;
            }
        }
        return res;
    }
};