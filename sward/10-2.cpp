class Solution {
   public:
    int numWays(int n) {
        // f[n] = f[n-1] + f[n-2]
        const int MOD = 1e9 + 7;
        if (n == 0) return 1;
        if (n == 1) return 1;
        int p = 1, q = 1, t;
        while (--n) {
            t = (p + q) % MOD;
            p = q;
            q = t;
        }
        return q;
    }
};