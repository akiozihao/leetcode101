//
// Created by akio on 2020/10/10.
//
#include <vector>
#include <algorithm>

using namespace std;

int findMinArrowShots(vector<vector<int>> &points) {
    if(points.empty()) return 0;
    sort(points.begin(),points.end(),[](vector<int> a,vector<int> b){
        return a[1] < b[1];
    });
    int prev = points[0][1],count =1;
    for(int i=1;i<points.size();++i){
        if(points[i][0] > prev) {
            ++count;
            prev = points[i][1];
        }
    }
    return count;
}