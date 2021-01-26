//
// Created by akio on 2021/1/26.
//
#include <vector>
#include <unordered_map>
#include <bitset>
using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes) {
        if (dominoes.empty() || dominoes.size() < 2) return 0;
        unordered_map<int, int> m;
        for (auto &d:dominoes) {
            ++m[(1 << d[0]) | (1 << d[1])];
        }
        int res = 0;
        for (auto &p:m) {
            if (p.second >= 2)
                res += p.second * (p.second - 1) / 2;
        }
        return res;
    }

    int numEquivDominoPairs2(vector<vector<int>> &dominoes) {
        if (dominoes.empty() || dominoes.size() < 2) return 0;
        unordered_map<bitset<999>, int> m;
        for (auto &d:dominoes) {
            bitset<999> b;
            b[d[0]] = true;
            b[d[1]] = true;
            ++m[b];
        }
        int res = 0;
        for (auto &p:m) {
            if (p.second >= 2)
                res += p.second * (p.second - 1) / 2;
        }
        return res;
    }

};