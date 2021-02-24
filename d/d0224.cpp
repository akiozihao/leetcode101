#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        if (A.empty() || A[0].empty()) return A;
        int m = A.size(), n = A[0].size(), l, r;
        for (int i = 0; i < n; ++i) {
            l = 0, r = n - 1;
            while (l < r) {
                swap(A[i][l++], A[i][r--]);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                A[i][j] = A[i][j] == 0 ? 1 : 0;
            }
        }
        return A;
    }
};