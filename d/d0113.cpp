//
// Created by akio on 2021/1/13.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        int n = edges.size();
        vector<int> parents(n + 1);
        for (int i = 1; i < parents.size(); ++i) {
            parents[i] = i;
        }
        for (auto &edge:edges) {
            int n1 = edge[0], n2 = edge[1];
            if (find(parents, n1) != find(parents, n2)) {
                connect(parents, n1, n2);
            } else {
                return edge;
            }
        }
        return vector<int>{};
    }

private:
    int find(vector<int> &f, int i) {
        if (f[i] == i) return i;
        int nf = find(f, f[i]);
        f[i] = nf;
        return nf;
    }

    void connect(vector<int> &f, int x, int y) {
        int fx = find(f, x);
        int fy = find(f, y);
        f[fx] = fy;
    }
};