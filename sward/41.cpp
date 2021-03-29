#include <bits/stdc++.h>

using namespace std;

class MedianFinder {
   public:
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num) {
        if (small.empty() || num <= small.top()) {
            small.push(num);
        } else
            large.push(num);
    }

    double findMedian() {
        cout << 
        if (small.size() == large.size()) {
            return 0.5 * (small.top() + large.top());
        } else
            return (double)small.top();
    }

   private:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<>> large;
    void balance() {
        if (small.size() > large.size() + 1) {
            large.push(small.top());
            small.pop();
        } else if (large.size() > small.size()) {
            small.push(large.top());
            large.pop();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */