//
// Created by akio on 2020/12/6.
//
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==0) return {};
        vector<vector<int>> res(numRows);
        for(int i=0;i<numRows;++i){
            res[i].resize(i+1);
            res[i][0] = res[i][i] = 1;
            for(int j=1;j<i;++j){
                res[i][j] = res[i-1][j] + res[i-1][j-1];
            }
        }
        return res;
    }
};