//
// Created by akio on 2021/1/3.
//
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int minOperations(vector<int> &target, vector<int> &arr) {
        map<int, int> A;
        for (int i = 0; i < target.size(); ++i) {
            A[target[i]] = i;
        }
        vector<int> a;
        for (auto &x:arr) {
            if (A.count(x)) a.push_back(A[x]);
        }
        vector<int> d;
        for (auto &x:a) {
            auto it = lower_bound(d.begin(), d.end(), x);
            if (it == d.end()) {
                d.push_back(x);
            } else {
                *it = x;
            }
        }
        return target.size() - d.size();
    }
};