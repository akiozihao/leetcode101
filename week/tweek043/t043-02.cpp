//
// Created by akio on 2021/1/9.
//
#include <string>
#include <map>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> stack1, stack2;
        int res = 0;
        if (x > y) {
            swap(x, y);
            reverse(s.begin(), s.end());
        }
        // 先处理ba
        for (char c:s) {
            if (c != 'a') stack1.push(c);
            else {
                if (!stack1.empty() && stack1.top() == 'b') {
                    stack1.pop();
                    res += y;
                } else {
                    stack1.push(c);
                }
            }
        }
        // 再处理 ab
        while (!stack1.empty()) {
            char c = stack1.top();
            stack1.pop();
            if (c != 'a') stack2.push(c);
            else {
                if (!stack2.empty() && stack2.top() == 'b') {
                    stack2.pop();
                    res += x;
                } else {
                    stack2.push(c);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    string s1 = "abba";
    cout << s.maximumGain(s1, 1926, 4320);
}