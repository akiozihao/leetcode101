//
// Created by akio on 2021/2/4.
//
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> pre(n + 1, 0);
        for (int i = 1; i < pre.size(); ++i) {
            pre[i] = pre[i - 1] + nums[i - 1];
        }
        int res = INT_MIN;
        for(int i=1;i<pre.size()-k;++i){
            res = max(res,pre[i+k]-pre[i-1]);
        }
        return double(res) / k;
    }
};