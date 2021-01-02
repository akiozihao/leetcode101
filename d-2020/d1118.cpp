//
// Created by akio on 2020/11/18.
//
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int sum = 0,total = 0, sz = gas.size(), idx = 0;
        if (sz != cost.size()) return -1;
        for (int i = 0; i < sz; ++i) {
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if (sum < 0) {
                sum = 0;
                idx = i + 1;
            }
        }
        return total >=0 ? idx : -1;
    }
};