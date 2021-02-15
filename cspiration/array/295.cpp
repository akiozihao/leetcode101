//
// Created by akio on 2021/2/9.
//

#include <bits/stdc++.h>

using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if(small.empty() || num <= small.top()){
            small.push(num);
        }else{
            large.push(num);
        }
        makeBalance();
    }

    double findMedian() {
        if(small.size() == large.size()){
            return 0.5 * (small.top() + large.top());
        }else{
            return small.top();
        }
    }

private:
    priority_queue<int> small;
    priority_queue<int,vector<int>,greater<>> large;
private:
    void makeBalance(){
        if(small.size() < large.size()){
            small.push(large.top());
            large.pop();
        }else if(small.size() > large.size() + 1){
            large.push(small.top());
            small.pop();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */