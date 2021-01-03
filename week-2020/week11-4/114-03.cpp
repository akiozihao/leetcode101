//
// Created by akio on 2020/11/29.
//
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int mn = *min_element(nums.begin(),nums.end());
        unordered_map<int,int> m;
        int n = nums.size();
        int i = n / 2-1;
        while(i>=0){
            ++m[nums[i] + nums[n-1-i]];
            --i;
        }
        sort(m.begin(),m.end(),[&](pair<int,int> a,pair<int,int>b){
            return a.second >= b.second;
        });
        for(auto pair:m){
            if(pair.first <= mn)
                continue;
            else{
                return n - pair.second;
            }
        }
        return 0;
    }
};