//
// Created by akio on 2021/2/9.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int> &A, int K) {
        return atMostDistinct(A, K) - atMostDistinct(A, K - 1);
    }

private:
    int atMostDistinct(vector<int> &A, int K) {
        int n = A.size();
        vector<int> freq(n + 1, 0);
        int left = 0, right = 0, cnt = 0, res = 0;
        while (right < n) {
            if (freq[A[right]] == 0) {
                ++cnt;
            }
            ++freq[A[right++]];
            while (cnt > K) {
                freq[A[left]]--;
                if (freq[A[left]] == 0) --cnt;
                ++left;
            }
            res += right - left;
        }
        return res;
    }
};