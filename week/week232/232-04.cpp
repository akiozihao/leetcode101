#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maximumScore(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> left(n, -1), right(n, n);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        st = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int l = left[i] + 1, r = right[i] - 1;
            if(l<=k && r >=k){
                res = max(res,(r-l+1)*nums[i]);
            }
        }
        return res;
    }
};