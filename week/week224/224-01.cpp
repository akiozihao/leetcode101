//
// Created by akio on 2021/1/17.
//
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countGoodRectangles(vector<vector<int>> &rectangles) {
        if (rectangles.empty() || rectangles[0].empty()) return 0;
        unordered_map<int, int> m;
        int mx = 0, b;
        for (auto &r:rectangles) {
            b = min(r[0], r[1]);
            mx = max(mx, b);
            ++m[b];
        }
        return m[mx];
    }
};