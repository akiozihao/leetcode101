//
// Created by akio on 2021/1/15.
//
#include <vector>
#include <cmath>

using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums) {
        if (nums.empty()) return;
        data = nums;
        double root = sqrt(data.size());
        len = ceil(data.size() / root);
        block.resize(len);
        for (int i = 0; i < data.size(); ++i) {
            block[i / len] += data[i];
        }
    }

    void update(int index, int val) {
        int idx = index / len;
        block[idx] += val - data[index];
        data[index] = val;
    }

    int sumRange(int left, int right) {
        int sum = 0;
        int start = left / len, end = right / len;
        if (start == end) {
            for (int k = left; k <= right; ++k) {
                sum += data[k];
            }
            return sum;
        }
        for (int k = left; k < (start + 1) * len; ++k) {
            sum += data[k];
        }
        for (int k = start + 1; k < end; ++k) {
            sum += block[k];
        }
        for (int k = end * len; k <= right; ++k) {
            sum += data[k];
        }
        return sum;
    }

private:
    vector<int> data, block;
    int len;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */