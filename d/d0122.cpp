//
// Created by akio on 2021/1/22.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int> &A, int K) {
        vector<int> res;
        int n = A.size(), remain = 0;
        for (int i = n - 1; i >= 0; ++i) {
            int t = A[i] + K % 10 + remain;
            res.push_back(t % 10);
            remain = t / 10;
            K /= 10;
        }
        while (K) {
            res.push_back(K % 10);
            K /= 10;
        }
        return {res.end(), res.begin()};
    }
};