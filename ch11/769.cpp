//
// Created by akio on 2021/1/12.
//
#include <vector>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int> &arr) {
        int res = 0, ma = 0;
        for (int i = 0; i < arr.size(); ++i) {
            ma = max(ma, arr[i]);
            if (ma == i) ++res;
        }
        return res;
    }
};