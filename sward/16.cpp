class Solution {
   public:
    double myPow(double x, int n) {
        double res = 1.0;
        for (int i = n; i != 0; i >>= 1) {
            if (i % 2) res *= x;
            x *= x;
        }
        return n < 0 ? 1 / res : res;
    }
};