//
// Created by akio on 2020/12/29.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        if (houses.empty()) return 0;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int res = 0, n = heaters.size();
        for (const int &h:houses) {
            int left = 0, right = n;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (heaters[mid] < h) left = mid + 1;
                else right = mid;
            }
            int dist1 = (right == n) ? INT_MAX : heaters[right] - h;
            int dist2 = (right == 0) ? INT_MAX : h - heaters[right - 1];
            res = max(res, min(dist1, dist2));
        }

        return res;
    }
};