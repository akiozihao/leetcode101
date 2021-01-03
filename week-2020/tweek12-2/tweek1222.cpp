//
// Created by akio on 2020/12/26.
//
#include <vector>
using namespace std;
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        if(customers.empty()) return 0;
        int free = 0;
        double wait = 0;
        for(const vector<int> &c:customers){
            free = max(free,c[0]) + c[1];
            wait += free - c[0];
        }
        return wait / customers.size();
    }
};