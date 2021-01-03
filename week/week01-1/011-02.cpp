//
// Created by akio on 2021/1/3.
//
#include <vector>
#include <map>

using namespace std;
const int MOD = 1e9 + 7;

class Solution {
public:
    int countPairs(vector<int> &deliciousness) {
        map<int, int> cnt;
        for (auto &v:deliciousness) {
            cnt[v]++;
        }
        int res = 0;
        for (const auto&[k, v]:cnt) {
            for (int x = 1; x <= (1 << 21); x *= 2) {
                int nk = x - k;
                if (nk < k) continue;
                if (cnt.find(nk) != cnt.end()) {
                    if (nk != k) {
                        res += 1LL * cnt[nk] * cnt[k] % MOD;
                        if (res >= MOD) res -= MOD;
                    } else {
                        res += 1LL * v * (v - 1) / 2 % MOD;
                        if (res >= MOD) res -= MOD;
                    }
                }
            }
        }
        return res;
    }
};