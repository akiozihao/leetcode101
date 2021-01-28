//
// Created by akio on 2021/1/28.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1,1);
        res[0] = 1;
        for (int i = 1; i <= rowIndex; ++i) {
            for (int j = i; j >= 1; --j) {
                res[j] += res[j-1];
            }
        }
        return res;
    }
};