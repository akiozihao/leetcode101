//
// Created by akio on 2021/2/21.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> b(n);
        for (int i = 0; i < boxes.size(); ++i) {
            b[i] = boxes[i] - '0';
        }
        vector<int> pre(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i - 1] + b[i - 1];
        }
        vector<int> erp(n + 1, 0);
        for (int i = n - 2; i >= 0; --i) {
            erp[i] = erp[i + 1] + b[i + 1];
        }
        vector<int> res(n), go(n), back(n);
        go[0] = 0;
        for (int i = 1; i < n; ++i) {
            go[i] = go[i - 1] + pre[i];
        }
        back[n - 1] = 0;
        for (int i = n - 2; i >= 0; --i) {
            back[i] = back[i + 1] + erp[i];
        }
        for (int i = 0; i < n; ++i) {
            res[i] = go[i] + back[i];
        }
        return res;
    }
        void cc(vector<int> &a){
            for(auto i:a){
                cout << i << ' ';
            }
            cout << endl;
        }
};