//
// Created by akio on 2021/2/9.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 延迟删除
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        priority_queue<int> pq;
        unordered_map<int, int> m;
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            pq.push(nums[i]);
        }
        res.push_back(pq.top());
        for (int i = k; i <= nums.size(); ++i) {
            pq.push(nums[i]);
            ++m[nums[i - k]];
            while (!pq.empty() && m[pq.top()] > 0) {
                int t = pq.top();
                --m[t];
                pq.pop();
            }
            res.push_back(pq.top());
        }
        return res;
    }

    // 单调队列 单调递减
    vector<int> maxSlidingWindow2(vector<int> &nums, int k) {
        int n = nums.size();
        deque<int> q;
        for (int i = 0; i < k; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        vector<int> res = {nums[q.front()]};
        for (int i = k; i < n; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            while (q.front() <= i - k) {
                q.pop_front();
            }
            res.push_back(nums[q.front()]);
        }
        return res;
    }

};