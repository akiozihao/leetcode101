#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents) {
        int n = classes.size();
        vector<int> total(n), pass(n);
        for (int i = 0; i < n; ++i) {
            total[i] = classes[i][1];
            pass[i] = classes[i][0];
        }
        auto calc = [&](int idx) {
            double original = (double)pass[idx] / total[idx];
            double update = (double)(pass[idx] + 1) / (double)(total[idx] + 1);
            return update - original;
        };
        priority_queue<pair<double, int>> pq;
        for (int i = 0; i < n; ++i) {
            pq.emplace(calc(i), i);
        }
        while (extraStudents) {
            extraStudents--;
            auto [delta, idx] = pq.top();
            pq.pop();
            pass[idx]++;
            total[idx]++;
            pq.emplace(calc(idx), idx);
        }
        double res = 0.0;
        for (int i = 0; i < n; ++i) {
            res += (double)pass[i] / (double)total[i];
        }
        return res / n;
    }
};