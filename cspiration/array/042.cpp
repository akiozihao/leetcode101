//
// Created by akio on 2021/2/1.
//
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        if (height.empty()) return 0;
        int res = 0;
        stack<int> st;
        // 减小栈
        for (int i = 0; i < height.size(); ++i) {
            if (st.empty() || height[i] <= height[st.top()]) {
                st.push(i);
            } else {
                while (!st.empty() && height[st.top()] < height[i]) {
                    int bottom = st.top();
                    st.pop();
                    if (!st.empty()) {
                        int left = st.top();
                        res += (min(height[left], height[i]) - height[bottom]) * (i - left - 1);
                    }
                }
                st.push(i);
            }
        }
        return res;
    }

    int trap2(vector<int> &height) {
        if (height.empty()) return 0;
        int res = 0;
        stack<int> st;
        // 减小栈
        for (int i = 0; i < height.size();) {
            if (st.empty() || height[i] <= height[st.top()]) {
                st.push(i++);
            } else {
                int b = st.top();
                st.top();
                if (st.empty()) continue;
                res += (min(height[i], height[st.top()]) - height[b]) * (i - st.top() - 1);
            }
        }
        return res;
    }

};