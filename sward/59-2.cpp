#include <bits/stdc++.h>
using namespace std;
class MaxQueue {
   public:
    MaxQueue() {}

    int max_value() {
        if (d.empty()) return -1;
        return d.front();
    }

    void push_back(int value) {
        while (!d.empty() && d.back() < value) {
            d.pop_back();
        }
        d.push_back(value);
        q.push(value);
    }

    int pop_front() {
        if (q.empty()) return -1;
        int res = q.front();
        if (res == d.front()) {
            d.pop_front();
        }
        q.pop();
        return res;
    }

   private:
    queue<int> q;
    deque<int> d;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */