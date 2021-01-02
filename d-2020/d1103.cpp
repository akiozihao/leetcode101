//
// Created by akio on 2020/11/3.
//
#include <vector>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int> &A) {
        int sz = A.size();
        int i = 0;
        while (i + 1 < sz && A[i] < A[i + 1])
            ++i;
        if (i == 0 || i == sz - 1)
            return false;
        while (i + 1 < sz && A[i] > A[i + 1])
            ++i;
        return i == sz - 1;
    }
};