//
// Created by akio on 2021/1/10.
//

// 判断一个整数是否为质数
// 从 1 到 n 遍历，假设当前遍历到 m，则把所有小于n的并且是m的倍数的整数标记为和数
// 遍历完成后没有被标记为和数的数字即为质数
// leetcode 204
#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        vector<int> prime(n, true);
        for (int i = 2; i < n; ++i) {
            if (!prime[i]) continue;
            ++res;
            if ((long long) i * i < n) {
                for (int j = i * i; j<n;j+=i) {
                    prime[j] = 0;
                }
            }
        }
        return res;
    }
};