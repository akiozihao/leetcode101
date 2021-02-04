//
// Created by akio on 2021/1/31.
//

#include <vector>

using namespace std;

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        vector<int> cnt(46);
        for (int i = lowLimit; i <= highLimit; ++i) {
            int s = 0;
            for (int j = i; j > 0; j /= 10) {
                s += j % 10;
            }
            ++cnt[s];
        }
        return *max_element(cnt.begin(), cnt.end());
    }
};