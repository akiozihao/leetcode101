//
// Created by akio on 2021/1/14.
//
#include <queue>
#include <unordered_set>
#include <climits>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<int, vector<int>, greater<>> pq;
        unordered_set<long> visited;
        vector<int> primes{2, 3, 5};
        pq.push(1);
        int cnt = 1;
        while (cnt < n) {
            int cur = pq.top();
            ++cnt;
            pq.pop();
            for (int &p:primes) {
                long next = (long) cur * p;
                if (!visited.count(next) && next <= INT_MAX) {
                    pq.push(next);
                    visited.insert(next);
                }
            }
        }
        return pq.top();
    }
};