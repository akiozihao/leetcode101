//
// Created by akio on 2021/1/13.
//
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        if (heights.empty()) return 0;
        heights.push_back(0);
        int n = heights.size(), res = 0, i = 0;
        stack<int> st;
        while (i < n) {
            if (st.empty() || heights[i] > heights[st.top()]) {
                st.push(i++);
            } else {
                int t = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                res = max(res, heights[t] * (i - left - 1));
            }
        }
        return res;
    }
};