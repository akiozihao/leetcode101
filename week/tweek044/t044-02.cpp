//
// Created by akio on 2021/1/23.
//

#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <bitset>

using namespace std;
const int N = 500;
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>> &languages, vector<vector<int>> &friendships) {
        int m = languages.size();
        vector<bitset<N>> skill(m);
        for (int i = 0; i < m; ++i) {
            for (auto &x:languages[i]) {
                skill[i][x - 1] = 1;
            }
        }
        vector<bool> flag(friendships.size());
        for (int i = 0; i < (int) friendships.size(); ++i) {
            auto &v = friendships[i];
            int x = v[0] - 1, y = v[1] - 1;
            if ((skill[x] & skill[y]).count() == 0) flag[i] = true;
        }
        int res = 1e9;
        for (int k = 0; k < n; ++k) {
            vector<bool> mark(m);
            for (int i = 0; i < (int) friendships.size(); ++i) {
                if (flag[i]) {
                    int x = friendships[i][0] - 1, y = friendships[i][1] - 1;
                    if (!skill[x][k]) mark[x] = true;
                    if (!skill[y][k]) mark[y] = true;
                }
            }
            int cur = 0;
            for (int i = 0; i < m; ++i)
                cur += mark[i];
            res = min(res, cur);
        }
        return res;
    }
};