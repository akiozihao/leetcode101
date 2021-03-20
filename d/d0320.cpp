
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_set<string> ust{"+", "-", "*", "/"};
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty()) return 0;
        stack<int> st;
        for (const string& s : tokens) {
            if (!ust.count(s)) {
                st.push(stoi(s));
            } else {
                int val2 = st.top();
                st.pop();
                int val1 = st.top();
                st.pop();
                switch (s[0]) {
                    case '+':
                        st.push(val1 + val2);
                        break;
                    case '-':
                        st.push(val1 - val2);
                        break;
                    case '*':
                        st.push(val1 * val2);
                        break;
                    case '/':
                        st.push(val1 / val2);
                        break;
                    default:
                        break;
                }
            }
        }
        return st.top();
    }

private:
    int stoi(const string& s) {
        int val = 1;
        if (s[0] == '-') {
            return -1 * stoi(s, 1);
        } else
            return stoi(s, 0);
    }
    int stoi(const string& s, int idx) {
        int val = 0;
        for (int i = idx; i < s.size(); ++i) {
            val = val * 10 + (s[i] - '0');
        }
        return val;
    }
};

int main() {
    vector<string> s {"17","22","-9","/","+"};
    Solution solution;
    solution.evalRPN(s);
}