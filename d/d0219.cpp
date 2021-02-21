//
// Created by akio on 2021/2/19.
//
#include <vector>

using namespace std;


class Solution {
public:
    int longestOnes(vector<int> &A, int K) {
        if (A.empty()) return 0;
        int n = A.size();
        if (K >= n) return n;
        int l = 0, r = 0, cnt = 0, res = 0;
        while (r < n) {
            while (r < n && A[r] == 1) ++r;
            while (l < r && cnt > K) {
                if (A[l] == 0) --cnt;
                ++l;
            }
            res = max(res, r - l);
            ++cnt;
            ++r;
        }
        if (cnt <= K) {
            res = max(res, r - l);
        }
        return res;
    }
};