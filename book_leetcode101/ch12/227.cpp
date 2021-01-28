//
// Created by akio on 2021/1/21.
//
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        if (s.empty()) return 0;
        stack<int> st;
        char sign = '+';
        int num = 0, pre;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (isdigit(c))
                num = num * 10 + (c - '0');
            if ((!isdigit(c) && c != ' ') || i == s.size() - 1) {
                switch (sign) {
                    case '+':
                        st.push(num);
                        break;
                    case '-':
                        st.push(-num);
                        break;
                    case '*':
                        pre = st.top();
                        st.pop();
                        st.push(pre * num);
                        break;
                    case '/':
                        pre = st.top();
                        st.pop();
                        st.push(pre / num);
                        break;
                }
                sign = c;
                num = 0;
            }
        }
        int res = 0;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};
#include <iostream>
int main() {
    Solution s;
    cout << s.calculate(" 3/2 ");
}