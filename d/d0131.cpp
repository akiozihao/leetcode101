//
// Created by akio on 2021/1/31.
//
#include <vector>
#include <numeric>
#include <string>
#include <unordered_map>

using namespace std;

class UF {
private:
    vector<int> parent;
    vector<int> size;
    int setCount;
    int n;
public:
    UF(int _n) : n(_n), setCount(_n), parent(_n), size(_n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int findset(int x) {
        return parent[x] == x ? x : parent[x] = findset(parent[x]);
    }

    bool unite(int x, int y) {
        x = findset(x);
        y = findset(y);
        if (x == y) {
            return false;
        }
        if (size[x] < size[y]) {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
        --setCount;
        return true;
    }

    bool connected(int x, int y) {
        return findset(x) == findset(y);
    }

    [[nodiscard]] int getSetCount() const {
        return setCount;
    }
};

class Solution {
public:
    int numSimilarGroups(vector<string> &strs) {
        int n = strs.size();
        int m = strs[0].size();
        UF uf(n);

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (uf.connected(i, j)) continue;
                if (check(strs[i], strs[j], m)) {
                    uf.unite(i, j);
                }
            }
        }
        return uf.getSetCount();
    }

private:
    bool check(string &x, string &y, int m) {
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            if (x[i] != y[i]) ++cnt;
            if (cnt > 2) return false;
        }
        return true;
    }
};