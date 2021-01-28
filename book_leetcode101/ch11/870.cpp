//
// Created by akio on 2021/1/15.
//
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int> &A, vector<int> &B) {
        vector<int> res;
        multiset st(A.begin(), A.end());
        for (int i = 0; i < B.size(); ++i) {
            auto it = (*st.rbegin() <= B[i]) ? st.begin() : st.upper_bound(B[i]);
            res.push_back(*it);
            st.erase(it);
        }
        return res;
    }
};