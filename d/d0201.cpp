//
// Created by akio on 2021/2/1.
//
#include <vector>
#include <numeric>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int> &A, vector<int> &B) {
        int suma = accumulate(A.begin(), A.end(), 0);
        int sumb = accumulate(B.begin(), B.end(), 0);
        int d = (suma - sumb) / 2;
        unordered_set<int> st(A.begin(), A.end());
        for (auto &y:B) {
            int x = d + y;
            if (st.count(x)) {
                return {x, y};
            }
        }
        return {};
    }
};