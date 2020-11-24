//
// Created by akio on 2020/11/2.
//
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> st1{nums1.begin(), nums2.end()}, res;
        for (int n2:nums2) {
            if (st1.count(n2)) {
                res.insert(n2);
            }
        }
        return vector<int>{res.begin(), res.end()};
    }
};