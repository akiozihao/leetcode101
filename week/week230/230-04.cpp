#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> res(n, 1.0e20);
        stack<int> st;
        for (int i = n - 1; i >= 0; --i) {
            while (st.size() && res[st.top()] > 0 &&
                   (cars[i][1] <= cars[st.top()][1] ||
                    (double)(cars[st.top()][0] - cars[i][0]) /
                            (double)(cars[i][1] - cars[st.top()][1]) >
                        res[st.top()])) {
                st.pop();
            }
            if (st.empty() || cars[i][1] <= cars[st.top()][1]) {
                res[i] = -1.0;
            } else {
                res[i] = (double)(cars[st.top()][0] - cars[i][0]) /
                         (double)(cars[i][1] - cars[st.top()][1]);
            }
            st.push(i);
        }
        return res;
    }
};