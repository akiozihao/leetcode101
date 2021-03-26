#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int idx = 0;
        for (const int& x : pushed) {
            stk.push(x);
            while (!stk.empty() && (stk.top() == popped[idx])) {
                stk.pop();
                ++idx;
            }
        }
        return stk.empty();
    }
};