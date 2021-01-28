//
// Created by akio on 2020/10/17.
//
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> counts;
        int max_count = 0;
        for (const int &num:nums)
            max_count = max(max_count, ++counts[num]);
        vector<vector<int>> buckets(max_count + 1);
        for (const auto &count:counts) {
            buckets[count.second].push_back(count.first);
        }
        vector<int> res;
        for (int i = max_count; i >= 0 && res.size() < k; --i) {
            for (const int &num:buckets[i]) {
                res.push_back(num);
                if (res.size() == k) break;
            }
        }
        return res;
    }

    vector<int> topKFrequent2(vector<int> &nums, int k) {
        unordered_map<int, int> m;
        priority_queue<pair<int, int>> q;
        vector<int> res;
        for (auto a:nums) ++m[a];
        for (auto it:m) q.push({it.second, it.first});
        for (int i = 0; i < k; ++i) {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }


};