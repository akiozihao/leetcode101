//
// Created by akio on 2021/1/11.
//
#include <string>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int getf(vector<int> &f, int x) {
        if (f[x] == x) return x;
        int nf = getf(f, f[x]);
        f[x] = nf;
        return nf;
    }

    void add(vector<int> &f, int x, int y) {
        int fx = getf(f,x);
        int fy = getf(f,y);
        f[fx] = fy;
    }

    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
        int n = s.size();
        vector<int> f(n, -1);
        for (int i = 0; i < f.size(); ++i) {
            f[i] = i;
        }
        for (const vector<int> &pair:pairs) {
            if(pair[0]==pair[1]) continue;
            add(f, pair[0], pair[1]);
        }
        unordered_map<int, multiset<int>> m;
        for (int i = 0; i < f.size(); ++i) {
            int fi = getf(f, i);
            m[fi].insert(s[i]);
        }
        string res;
        for (int i = 0; i < n; ++i) {
            char t = *m[f[i]].begin();
            m[f[i]].erase(m[f[i]].begin());
            res += t;
        }
        return res;
    }
};