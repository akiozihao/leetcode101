//
// Created by akio on 2021/1/28.
//
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    int hIndex(vector<int> &citations) {
        if (citations.empty()) return 0;
        sort(citations.begin(), citations.end(), greater<>());
        for (int i = 0; i < citations.size(); ++i) {
            if (i >= citations[i]) return i;
        }
        return citations.size();
    }
};