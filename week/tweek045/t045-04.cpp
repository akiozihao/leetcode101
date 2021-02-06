//
// Created by akio on 2021/2/5.
//

#include <bits/stdc++.h>

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
};

class Solution {
public:
    int maxValue(vector<vector<int>> &events, int k) {
        if (events.empty() || k == 0)return 0;
        int n = events.size();
        UF uf(n);
        sort(events.begin(), events.end(), [](auto &a, auto &b) {
            return a[0] < b[0];
        });
        int end;
        for (int i = 0; i < n; ++i) {
            if (uf.findset(i) != i) continue;
            end = events[i][1];
            int l = i + 1, r = n;
            while (l < r) {
                int m = l + (r - l) / 2;
                if (events[m][0] < end) l = m + 1;
                else r = m;
            }
            for (int j = r; j < n; ++j) {
                uf.unite(i, j);
            }
        }
        unordered_map<int, priority_queue<int>> m;
        for (int i = 0; i < n; ++i) {
            int key = uf.findset(i);
            m[key].push(events[i][2]);
        }
        int res = 0;
        for (auto &p:m) {
            auto pq = p.second;
            int cnt = 0;
            for (int i = 0; i < k; ++i) {
                cnt += pq.top();
                pq.pop();
            }
            res = max(res, cnt);
        }
        return res;
    }
};