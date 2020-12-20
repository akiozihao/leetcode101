//
// Created by akio on 2020/12/20.
//
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgeList, vector<vector<int>> &queries) {
        vector<vector<int>> len(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; ++i) {
            len[i][i] = 0;
        }
        for (const vector<int> &edge:edgeList) {
            int i = edge[0], j = edge[1], sz = edge[2];
            len[i][j] = len[j][j] = min(len[i][j], sz);
        }
        vector<bool> res(queries.size(), false);

        for (int i=0;i<queries.size();++i) {
            vector<int> &query = queries[i];
            int minlen = helper(len,query);
            if(minlen < query[2])
                res[i] = true;
        }
        return res;
    }

private:
    int helper(vector<vector<int>> &len,vector<int> &query){
        int n = len.size();
        vector<bool> visited(n,false);
        int i = query[0],j = query[1],limit = query[2];
        stack<int> stack;
        stack.push(i);
        visited[i] = true;
        int sz = 0;
        while(!stack.empty()){
            int k = stack.top();
            stack.pop();
            for(int i=0;i<n;++i){
                if(len[k][i]!=INT_MAX && !visited[i]){
                    sz += len[k][i];
                    stack.push(i);
                    visited[i] = true;
                    if(sz > limit) break;
                    if(i==j) return true;
                }
            }
        }
        return false;
    }
};