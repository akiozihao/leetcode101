//
// Created by akio on 2020/11/6.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int> &arr) {
        vector<int> bit(10001, 0);
        for (auto x:arr) {
            bit[x] = help(x);
        }
        sort(arr.begin(), arr.end(), [bit](int x, int y) {
            if (bit[x] < bit[y])
                return true;
            if (bit[x] > bit[y])
                return false;
            return x < y;
        });
        return arr;
    }

private:
    int help(int x) {
        int res = 0;
        while (x) {
            if (x % 2 == 1)
                ++res;
            x /= 2;
        }
        return res;
    }
};