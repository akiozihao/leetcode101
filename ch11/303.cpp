//
// Created by akio on 2021/1/14.
//
#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums) {
        pre.push_back(0);
        int sum = 0;
        for (int &i :nums) {
            sum += i;
            pre.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        return pre[j+1] - pre[i];
    }

private:
    vector<int> pre;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */