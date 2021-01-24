//
// Created by akio on 2021/1/23.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> waysToFillArray(vector<vector<int>> &queries) {
        int sz = queries.size();

        const int mod = 1e9 + 7;
        const int maxc = 15;
        int maxn = 0, maxk = 0;
        for (int i = 0; i < sz; ++i) {
            maxn = max(maxn, queries[i][0]);
            maxk = max(maxk, queries[i][1]);
        }
        vector<vector<int>> dp(maxn + 1, vector<int>(maxc + 1, 0));
        for (int i = 1; i <= maxc; ++i) {
            dp[1][i] = 1;
        }
        for (int i = 1; i <= maxn; ++i) {
            dp[i][0] = 1;
        }
        for (int i = 2; i <= maxn; ++i) {
            for (int j = 1; j <= maxc; ++j) {
                for (int k = 0; k <= j; ++k) {
                    dp[i][j] += dp[i - 1][j - k];
                    dp[i][j] %= mod;
                }
            }
        }
        vector<int> isPrime(maxk + 1, 1);
        vector<int> primes;
        for (int i = 2; i <= maxk; ++i) {
            if (isPrime[i] == 1) {
                primes.push_back(i);
            }
            for (int j = i * i; j <= maxk; j += i) {
                isPrime[j] = 0;
            }
        }
        vector<int> res(sz);
        for (int i = 0; i < sz; ++i) {
            int n = queries[i][0], k = queries[i][1];
            vector<int> cs;
            for (int p:primes) {
                if (p > k) {
                    break;
                }
                int cnt = 0;
                int left = k;
                while (left % p == 0) {
                    left /= p;
                    ++cnt;
                }
                if (cnt > 0) {
                    cs.push_back(cnt);
                }
            }
            long long ans = 1;
            for (int c:cs) {
                ans *= dp[n][c];
                ans %= mod;
            }
            res[i] = ans;
        }
        return res;
    }
};