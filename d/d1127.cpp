//
// Created by akio on 2020/11/27.
//
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> m;
        for(const int &a:A){
            for(const int &b:B){
                ++m[a+b];
            }
        }
        int res = 0;
        for(const int &c:C){
            for(const int &d:D){
                if(m.count(-(c+d)))
                    res += m[-(c+d)];
            }
        }
        return res;
    }
};