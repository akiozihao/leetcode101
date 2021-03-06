#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        if (points.empty()) return -1;
        int len = INT_MAX;
        int res = -1;
        for (int i = 0; i < points.size(); ++i) {
            auto p = points[i];
            if (p[0] == x || p[1] == y) {
                int t = abs(p[0] - x) + abs(p[1] - y);
                if (t < len) {
                    len = t;
                    res = i;
                }
            }
        }
        return res;
    }
};