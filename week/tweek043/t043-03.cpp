//
// Created by akio on 2021/1/9.
//
#include <vector>

using namespace std;
// 回溯
class Solution {
public:
    vector<int> res;
    vector<bool> used;

    bool make(int s, int n) {
        if (s == res.size()) return true;
        if (res[s] != -1) return make(s + 1, n);
        for (int cur = n; cur > 0; --cur) {
            if (used[cur]) continue;
            if (cur == 1) {
                res[s] = 1;
                used[1] = true;
                if (make(s + 1, n)) return true;
                used[1] = false;
                res[s] = -1;
                return false;
            }
            if (s + cur >= res.size()) continue;
            if (res[s + cur] == -1) {
                res[s] = res[s + cur] = cur;
                used[cur] = true;
                if (make(s + 1, n)) return true;
                res[s] = res[s + cur] = -1;
                used[cur] = false;
            }
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        res.resize(2*n-1,-1);
        used.resize(n + 1, false);
        make(0,n);
        return res;
    }
};