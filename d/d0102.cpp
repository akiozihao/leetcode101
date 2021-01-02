//
// Created by akio on 2021/1/2.
//
#include <vector>
#include <queue>
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        multiset<int> st;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            st.insert(nums[i]);
            if (i >= k) st.erase(st.find(nums[i - k]));
            if (i >= k - 1)res.push_back(*st.rbegin());
        }
        return res;
    }

    vector<int> maxSlidingWindow2(vector<int> &nums, int k) {
        vector<int> res;
        deque<int> q;
        for(int i=0;i<nums.size();++i){
            if(!q.empty() && q.front() == i-k) q.pop_front();
            while(!q.empty() && nums[q.back()] < nums[i]) q.pop_back();
            q.push_back(i);
            if(i>=k-1) res.push_back(nums[q.front()]);
        }
        return res;
    }
};

int main() {
    priority_queue<int, vector<int>> pq;
    pq.push(0);
    pq.push(1);
    cout << pq.top() << endl;
}