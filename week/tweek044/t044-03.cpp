//
// Created by akio on 2021/1/23.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> decode(vector<int> &encoded) {
        int n = encoded.size();
        vector<int> v(n + 1);
        int all = 0;
        for (int i = 0; i <= n + 1; ++i) {
            all ^= i;
        }
        int all_but_first = 0;
        for (int i = 1; i < n; i += 2) {
            all_but_first ^= encoded[i];
        }
        v[0] = all ^ all_but_first;
        for (int i = 1; i <= n; ++i) {
            v[i] = v[i - 1] ^ encoded[i - 1];
        }
        return v;
    }
};