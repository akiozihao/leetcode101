//
// Created by akio on 2021/1/18.
//
#include <vector>
#include <climits>
#include <stack>

using namespace std;

class Solution {
public:
    // 枚举宽 O(n^2)
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int h = INT_MAX;
            for (int j = i; j < n; ++j) {
                h = min(h, heights[j]);
                res = max(res, h * (j - i + 1));
            }
        }
        return res;
    }

    // 枚举高 O(n^2)
    int largestRectangleArea2(vector<int> &heights) {
        int n = heights.size();
        int res = 0;
        for (int mid = 0; mid < n; ++mid) {
            int h = heights[mid];
            int left = mid, right = mid;
            while (left >= 1 && heights[left - 1] >= h) {
                --left;
            }
            while (right < n - 1 && heights[right + 1] >= h) {
                ++right;
            }
            res = max(res, h * (right - left + 1));
        }
        return res;
    }

    // 单调栈
    int largestRectangleArea3(vector<int> &heights) {
        if (heights.empty()) return 0;
        heights.push_back(0);
        stack<int> st;
        int n = heights.size(), res = 0;
        int i = 0;
        while (i < n) {
            if (st.empty() || heights[i] >= heights[st.top()]) {
                st.push(i++);
            } else {
                int h = heights[st.top()];
                st.pop();
                int left = st.empty() ? 0 : st.top() + 1;
                int right = i - 1;
                res = max(res, h * (right - left + 1));
            }
        }
        return res;
    }

    // 单调栈
    int largestRectangleArea4(vector<int> &heights) {
        if (heights.empty()) return 0;
        heights.push_back(0);
        stack<int> st;
        int res = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int cur = st.top();
                st.pop();
                int left = st.empty() ? 0 : st.top() + 1;
                int right = i - 1;
                res = max(res, heights[cur] * (right - left + 1));
            }
            st.push(i);
        }
        return res;
    }
};