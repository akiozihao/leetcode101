//
// Created by akio on 2021/1/14.
//
#include <vector>
#include <climits>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int> &primes) {
        priority_queue<int, vector<int>, greater<>> pq;
        pq.push(1);
        int cnt = 1;
        unordered_set<long> visited;
        while (cnt < n) {
            int cur = pq.top();
            pq.pop();
            ++cnt;
            for (const auto &p:primes) {
                long next = (long) cur * p;
                if (!visited.count(next) && next <= INT_MAX) {
                    visited.insert(next);
                    pq.push(next);
                }
            }
        }
        return pq.top();
    }
};