//
// Created by akio on 2020/11/11.
//
#include <string>
#include <unordered_map>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        if (key.empty()) return 0;
        int n = ring.size(), m = key.size();
        vector<vector<int>> v(26);
        vector<vector<int>> memo(n, vector<int>(m));
        for (int i = 0; i < ring.size(); ++i) {
            v[ring[i] - 'a'].push_back(i);
        }
        return helper(ring, key, 0, 0, v, memo);
    }

private:
    int helper(string ring, string key, int x, int y, vector<vector<int>> &v, vector<vector<int>> &memo) {
        if (y == key.size()) return 0;
        if (memo[x][y]) return memo[x][y];
        int res = INT_MAX, n = ring.size();
        for (int k:v[key[y] - 'a']) {
            int diff = abs(x - k);
            int step = min(diff, n - diff);
            res = min(res, step + helper(ring, key, k, y + 1, v, memo));
        }
        return memo[x][y] = res + 1;
    }
};

int main() {
    Solution s;
    cout << s.findRotateSteps("godding", "godd");
}