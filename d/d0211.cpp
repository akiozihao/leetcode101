//
// Created by akio on 2021/2/11.
//
#include <bits/stdc++.h>
using namespace std;
class KthLargest {
public:
    KthLargest(int _k, vector<int>& nums) {
        k = _k;
        for(auto &n:nums){
            add(n);
        }

    }

    int add(int val) {
        if(pq.size() < k || val > pq.top()){
            pq.push(val);
        }
        if(pq.size()>k) pq.pop();
        return pq.top();
    }

private:
    priority_queue<int,vector<int>,greater<>> pq;
    int k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */