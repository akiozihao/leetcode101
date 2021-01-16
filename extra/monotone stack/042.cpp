//
// Created by akio on 2021/1/13.
//
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        stack<int> st;
        int i = 0, res = 0, n = height.size();
        while (i < n) {
            if (st.empty() || height[i] <= height[st.top()]) {
                st.push(i++);
            } else {
                int low = st.top();
                st.pop();
                if (st.empty()) continue;
                res += (min(height[st.top()], height[i]) - height[low]) * (i - st.top() - 1);
            }
        }
        return res;
    }
};