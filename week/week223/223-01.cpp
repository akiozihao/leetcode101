//
// Created by akio on 2021/1/10.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> decode(vector<int> &encoded, int first) {
        if (encoded.empty()) return {};
        vector<int> res;
        res.push_back(first);
        for (int i = 0; i < encoded.size() - 1; ++i) {
            res.push_back(res.back() ^ encoded[i]);
        }
        return res;
    }
};