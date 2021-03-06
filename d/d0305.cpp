#include <stack>
using namespace std;
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x) {
        if (st1.empty()) {
            front = x;
        }
        st1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        int t = st2.top();
        st2.pop();
        return t;
    }

    /** Get the front element. */
    int peek() {
        if (!st2.empty()) {
            return st2.top();
        }
        return front;
    }

    /** Returns whether the queue is empty. */
    bool empty() { return st1.empty() && st2.empty(); }

private:
    stack<int> st1, st2;
    int front;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */