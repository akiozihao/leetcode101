//
// Created by akio on 2020/11/9.
//
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b) {
            return sqrt(a[0] * a[0] + a[1] * a[1]) < sqrt(b[0] * b[0] + b[1] * b[1]);
        });
        return {points.begin(), points.begin() + K};
    }
};