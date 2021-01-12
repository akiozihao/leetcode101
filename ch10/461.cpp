//
// Created by akio on 2021/1/11.
//

class Solution {
public:
    int hammingDistance(int x, int y) {
        int t = x ^y;
        int res = 0;
        while (t) {
            res += t & 1;
            t >>= 1;
        }
        return res;
    }

    int hammingDistance2(int x, int y) {
        int t = x ^y, res = 0;
        while (t) {
            res += 1;
            t = t & (t - 1);
        }
        return res;
    }

};