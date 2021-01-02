//
// Created by akio on 2020/11/12.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int> &A) {
        int sz = A.size();
        int j = 1;
        for (int i = 0; i < sz; i += 2) {
            if (A[i] % 2 == 1) {
                while (A[j] % 2 == 1)
                    j += 2;
                swap(A[i], A[j]);
            }
        }
        return A;
    }
};