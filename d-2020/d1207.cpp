//
// Created by akio on 2020/12/7.
//
#include <vector>
using namespace std;
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size(),n = A[0].size();
        int res = m * (1 << (n-1));
        for(int j=1;j<n;++j){
            int cntOne = 0;
            for(int i=0;i<m;++i){
                if(A[i][0]==1)
                    cntOne += A[i][j];
                else
                    cntOne += (1-A[i][j]);
            }
            int k = max(cntOne,m-cntOne);
            res += k * (1 << (n-j-1));
        }
        return res;
    }
};