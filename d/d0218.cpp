//
// Created by akio on 2021/2/18.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int> &A, int K) {
        int n = A.size();
        vector<int> diff(n + 1, 0);
        int res = 0, cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += diff[i];
            if ((A[i] + cnt) % 2 == 0) {
                if (i + K > n) return -1;
                ++diff[i];
                --diff[i + K];
                ++cnt;
            }
        }
        return res;
    }

    int minKBitFlips2(vector<int> &A, int K) {
        int n = A.size();
        vector<int> reverse(n, 0);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if ((A[i] + reverse[i]) % 2 == 0) {
                if (i + K > n) return -1;
                for (int j = i; j < i + K; ++j) {
                    ++reverse[j];
                }
                ++res;
            }
        }
        return res;
    }

    int minKBitFlips3(vector<int> &A, int K) {
        int n = A.size();
        int res = 0, windowFlip = 0;
        for (int i = 0; i < n; ++i) {
            if (i - K >= 0 && A[i - K] > 1) {
                A[i - K] -= 2;
                --windowFlip;
            }
            if ((A[i] + windowFlip) % 2 == 0) {
                if (i + K > n) return -1;
                A[i] += 2;
                windowFlip++;
                res++;
            }
        }
        return res;
    }

};