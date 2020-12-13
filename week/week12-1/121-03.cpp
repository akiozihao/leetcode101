//
// Created by akio on 2020/12/13.
//
#include <vector>
using namespace std;
class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        if(stones.empty()) return 0;
        int sz = stones.size();
        vector<vector<int>> dp(sz,vector<int>(sz,0));
        for(int i=0;i<sz;++i){
            for(int j=i;j<sz;++j){
                if(j==i) dp[i][j] = stones[i];
                else dp[i][j] = dp[i][j-1] + stones[j];
            }
        }
        vector<vector<int>> res(sz,vector<int>(sz,0));
        for(int i=sz-1;i>=0;--i){
            for(int j=i;j<sz;++j){
                if(i==j){
                    res[i][j] = 0;
                }else if(j - i ==1){
                  res[i][j] = max(stones[i],stones[j]);
                }else {
                    res[i][j] = max(dp[i+1][j]-res[i+1][j],dp[i][j-1]-res[i][j-1]);
                }
            }
        }
        return res[0][sz-1];
    }
};