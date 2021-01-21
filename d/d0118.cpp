//
// Created by akio on 2021/1/18.
//
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class Solution {
private:
    vector<int> f;

    int find(vector<int> &f, int x) {
        if (f[x] == x) return x;
        int nf = find(f, f[x]);
        f[x] = nf;
        return nf;
    }

    void merge(vector<int> &f, int x, int y) {
        int fx = find(f, x), fy = find(f, y);
        f[fx] = fy;
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        int n = accounts.size();
        f.resize(1001);
        for (int i = 0; i < f.size(); ++i) {
            f[i] = i;
        }
        unordered_map<string, int> emailToIndex;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                if (emailToIndex.count(accounts[i][j])) {
                    merge(f, emailToIndex[accounts[i][j]], i);
                } else {
                    emailToIndex[accounts[i][j]] = i;
                }
            }
        }
        unordered_map<int, unordered_set<string>> dump;
        for (int i = 0; i < n; ++i) {
            int root = find(f, i);
            for (int j = 1; j < accounts[i].size(); ++j) {
                dump[root].insert(accounts[i][j]);
            }
        }
        vector<vector<string>> res;
        for (const auto& node:dump) {
            vector<string> v;
            int root = node.first;
            string name = accounts[root][0];
            v.push_back(name);
            for (auto &s:node.second) {
                v.emplace_back(s);
            }
            sort(v.begin(), v.end());
            res.push_back(v);
        }
        return res;
    }
};