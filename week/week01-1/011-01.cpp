//
// Created by akio on 2021/1/3.
//
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        if(boxTypes.empty() || truckSize==0) return 0;
        sort(boxTypes.begin(),boxTypes.end(),[](vector<int> &a,vector<int> &b){
            return a[1] > b[1];
        });
        int res = 0;
        for(int i=0;i<boxTypes.size();++i){
            res += min(boxTypes[i][0],truckSize) * boxTypes[i][1];
            truckSize -= min(boxTypes[i][0],truckSize);
            if(truckSize==0)
                break;
        }
        return res;
    }
};