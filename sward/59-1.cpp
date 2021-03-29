#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        // key:num, val: delete_times
        unordered_map<int, int> map;
        priority_queue<int> pq;
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            pq.push(nums[i]);
        }
        res.push_back(pq.top());
        for (int i = k; i < n; ++i) {
            pq.push(nums[i]);
            map[nums[i - k]]++;
            while (map.count(pq.top())) {
                if (--map[pq.top()] == 0) map.erase(pq.top());
                pq.pop();
            }
            res.push_back(pq.top());
        }
        return res;
    }
};