//
// Created by akio on 2021/1/21.
//
#include <vector>
#include <string>
#include <stack>
#include <list>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        if (s.empty()) return 0;
        list<char> v({s.begin(), s.end()});
        return helper(v);
    }

private:
    int helper(list<char> &v) {
        if (v.empty()) return 0;
        stack<int> st;
        char sign = '+';
        int num = 0, pre;
        while (!v.empty()) {
            char c = v.front();
            v.pop_front();
            if (isdigit(c))
                num = num * 10 + (c - '0');
            if (c == '(') {
                num = helper(v);
            }
            if ((!isdigit(c) && c != ' ') || v.size() == 0) {
                switch (sign) {
                    case '+':
                        st.push(num);
                        break;
                    case '-':
                        st.push(-num);
                        break;
                    case '*':
                        pre = st.top();
                        st.push(pre * num);
                        break;
                    case '/':
                        pre = st.top();
                        st.push(pre / num);
                        break;
                }
                sign = c;
                num = 0;
            }
            if (c == ')')
                break;
        }
        int res = 0;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};