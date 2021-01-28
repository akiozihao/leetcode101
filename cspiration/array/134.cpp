//
// Created by akio on 2021/1/28.
//
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        int cur = 0, total = 0, res = 0;
        for (int i = 0; i < n; ++i) {
            cur += gas[i] - cost[i];
            if (cur < 0) {
                cur = 0;
                res = i + 1;
            }
            total += gas[i] - cost[i];
        }
        return total >= 0 ? res : -1;
    }
};