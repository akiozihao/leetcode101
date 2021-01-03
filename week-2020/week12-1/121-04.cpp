//
// Created by akio on 2020/12/13.
//
#include <vector>

using namespace std;

class Solution {
public:
    int maxHeight(vector<vector<int>> &cuboids) {
        int n = cuboids.size();
        for (auto &cuboid:cuboids) {
            sort(cuboid.begin(), cuboid.end());
        }
        sort(cuboids.begin(), cuboids.end(), [](const auto &u, const auto &v) {
            return pair(u[2], u[0] + u[1]) < pair(v[2], v[0] + v[1]);
        });
        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if(cuboids[j][0] <= cuboids[i][0]
                && cuboids[j][1] <= cuboids[i][1]
                && cuboids[j][2] <= cuboids[i][2]){
                    res[i] = max(res[i],res[j]);
                }
            }
            res[i] += cuboids[i][2];
        }
        return *max_element(res.begin(),res.end());
    }
};