//
// Created by akio on 2021/2/8.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // O(lg(m)m + lg(n)n)
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        priority_queue<int> small;
        priority_queue<int, vector<int>, greater<>> large;
        for (int &i:nums1) {
            if (small.empty() || i > small.top()) {
                large.push(i);
            } else {
                small.push(i);
            }
            makeBalance(small, large);
        }
        for (int &i:nums2) {
            if (small.empty() || i > small.top()) {
                large.push(i);
            } else {
                small.push(i);
            }
            makeBalance(small, large);
        }
        if (small.size() > large.size()) {
            return small.top();
        } else {
            return 0.5 * (small.top() + large.top());
        }
    }

private:
    void makeBalance(priority_queue<int> &small, priority_queue<int, vector<int>, greater<>> &large) {
        if (large.size() > small.size()) {
            small.push(large.top());
            large.pop();
        }else if(small.size() > large.size() + 1){
            large.push(small.top());
            small.pop();
        }
    }
};