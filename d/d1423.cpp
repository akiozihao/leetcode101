//
// Created by akio on 2021/2/6.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxScore(vector<int> &cardPoints, int k) {
        int n = cardPoints.size();
        int sz = n - k;
        int sum = accumulate(cardPoints.begin(), cardPoints.begin() + sz, 0);
        int minSum = sum;
        for (int i = sz; i < n; ++i) {
            sum += cardPoints[i] - cardPoints[i - sz];
            minSum = min(minSum, sum);
        }
        return accumulate(cardPoints.begin(), cardPoints.end(), 0) - minSum;
    }
};