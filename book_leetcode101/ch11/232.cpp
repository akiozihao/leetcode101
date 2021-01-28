//
// Created by akio on 2021/1/12.
//
#include <stack>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        st1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        int ret = st2.top();
        st2.pop();
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
        return ret;
    }

    /** Get the front element. */
    int peek() {
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        int ret = st2.top();
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
        return ret;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return st1.empty();
    }

private:
    stack<int> st1, st2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */