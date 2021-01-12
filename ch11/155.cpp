//
// Created by akio on 2021/1/12.
//
#include <stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        st.push(x);
        if (mst.empty() || x <= mst.top()) mst.push(x);
    }

    void pop() {
        if (mst.top() == st.top()) mst.pop();
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return mst.top();
    }

private:
    stack<int> st;
    stack<int> mst;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */