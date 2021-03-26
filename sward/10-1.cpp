
class Solution {
   public:
    int fib(int n) {
        const int MOD = 1e9 + 7;
        int p = 0, q = 1, t;
        if (n == 0)
            return p;
        else if (n == 1)
            return q;
        else {
            while (--n) {
                t = (p + q) % MOD;
                p = q;
                q = t;
            }
        }
        return q;
    }
};