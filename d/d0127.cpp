//
// Created by akio on 2021/1/27.
//
#include <vector>
#include <numeric>

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

    int getsetCount() {
        return setCount;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges) {
        UF ufa(n), ufb(n);
        int res = 0;

        for (auto &edge:edges) {
            --edge[1];
            --edge[2];
        }

        for (const auto &edge:edges) {
            if (edge[0] == 3) {
                if (!ufa.unite(edge[1], edge[2])) {
                    ++res;
                } else {
                    ufb.unite(edge[1], edge[2]);
                }
            }
        }

        for (const auto &edge:edges) {
            if (edge[0] == 1) {
                if (!ufa.unite(edge[1], edge[2])) {
                    ++res;
                }
            } else if (edge[0] == 2) {
                if (!ufb.unite(edge[1], edge[2])) {
                    ++res;
                }
            }
        }
        if (ufa.getsetCount() != 1 || ufb.getsetCount() != 1) {
            return -1;
        }
        return res;
    }
};