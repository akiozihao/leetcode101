//
// Created by akio on 2020/11/26.
//
#include <vector>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int> &nums) {
        if (nums.empty() || nums.size() < 2) return 0;
        int sz = nums.size();
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        int d = max(1, (maxVal - minVal) / (sz - 1));
        int nBucket = (maxVal - minVal) / d + 1;
        vector<pair<int, int>> bucket(nBucket, {-1, -1});
        for (int i = 0; i < sz; ++i) {
            int idx = (nums[i] - minVal) / d;
            if (bucket[idx].first == -1) {
                bucket[idx].first = bucket[idx].second = nums[i];
            }else{
                bucket[idx].first = min(bucket[idx].first,nums[i]);
                bucket[idx].second = max(bucket[idx].second,nums[i]);
            }
        }
        int res = 0;
        int prev = -1;
        for(int i=0;i<nBucket;++i){
            if(bucket[i].first==-1) continue;
            if(prev!=-1){
                res = max(res,bucket[i].first-bucket[prev].second);
            }
            prev = i;
        }
        return res;
    }
};