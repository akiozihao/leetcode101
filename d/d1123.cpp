//
// Created by akio on 2020/11/23.
//
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>> &points) {
        if (points.empty()) return 0;
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });
        int res = 1, mx = points[0][1];
        for (const vector<int> &point:points) {
            if (mx < point[0]) {
                ++res;
                mx = point[1];
            }
        }
        return res;
    }
};