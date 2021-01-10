//
// Created by akio on 2021/1/10.
//
#include <vector>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class UF {
public:
    vector<int> fa;
    vector<int> sz;
    int n;
    int comp_cnt;
public:
    UF(int _n) : n(_n), comp_cnt(_n), fa(_n), sz(_n, 1) {
        iota(fa.begin(), fa.end(), 0);
    }

    int findset(int x) {
        return fa[x] == x ? x : fa[x] = findset(fa[x]);
    }

    bool unite(int x, int y) {
        x = findset(x);
        y = findset(y);
        if (x == y)
            return false;
        if (sz[x] < sz[y]) {
            swap(x, y);
        }
        fa[y] = x;
        sz[x] += sz[y];
        --comp_cnt;
        return true;
    }

    bool connected(int x, int y) {
        x = findset(x);
        y = findset(y);
        return x == y;
    }
};

#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    int getf(vector<int> &f, int x) {
        if (f[x] == x) return x;
        int nf = getf(f, f[x]);
        f[x] = nf;
        return nf;
    }

    void add(vector<int> &f, int x, int y) {
        int fx = getf(f, x);
        int fy = getf(f, y);
        f[fx] = fy;
    }

    int minimumHammingDistance(vector<int> &source, vector<int> &target, vector<vector<int>> &allowedSwaps) {
        int n = source.size();
        vector<int> f(n);
        for (int i = 0; i < n; ++i) {
            f[i] = i;
        }
        for (const auto &e:allowedSwaps) {
            add(f, e[0], e[1]);
        }
        unordered_map<int, unordered_multiset<int>> s, t;
        for (int i = 0; i < n; ++i) {
            int fa = getf(f, i);
            s[fa].insert(source[i]);
            t[fa].insert(target[i]);
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (s.find(i) == s.end()) continue;
            for (int x:s[i]) {
                if (t[i].find(x) == t[i].end()) {
                    ++res;
                } else {
                    t[i].erase(t[i].find(x));
                }
            }
        }
        return res;
    }
};