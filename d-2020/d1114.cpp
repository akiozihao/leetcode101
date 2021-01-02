//
// Created by akio on 2020/11/14.
//
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
        unordered_map<int, int> rank;
        for (int i = 0; i < arr2.size(); ++i) {
            rank[arr2[i]] = i;
        }
        sort(arr1.begin(), arr1.end(), [&](int a, int b) {
            if (rank.count(a) && rank.count(b))
                return rank[a] < rank[b];
            else if (!rank.count(a) && !rank.count(b))
                return a < b;
            else
                return rank.count(a) != 0;
        });
        return arr1;
    }
};