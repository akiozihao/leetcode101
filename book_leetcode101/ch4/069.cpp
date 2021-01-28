//
// Created by akio on 2020/10/13.
//

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return x;
        int l = 1, r = x, mid, sqrt;
        while (l <= r) {
            mid = l + (r - 1) / 2;
            sqrt = x / mid;
            if (sqrt == mid) {
                return mid;
            } else if (sqrt < mid) {
                l = mid + 1;
            } else
                r = mid - 1;
        }
        return r;
    }
};