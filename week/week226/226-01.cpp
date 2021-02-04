//
// Created by akio on 2021/1/31.
//
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> m;
        int res = 0;
        for (int i = lowLimit; i <= highLimit; ++i) {
            int n = 0, j = i;
            while (j) {
                n += j % 10;
                j /= 10;
            }
            m[n]++;
            if (m[n] > res) res = m[n];
        }
        return res;
    }
};