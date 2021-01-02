//
// Created by akio on 2020/11/15.
//
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> st;
        for (auto &n:num) {
            while (!st.empty() && st.back() > n && k) {
                st.pop_back();
                --k;
            }
            st.push_back(n);
        }
        while (k) {
            st.pop_back();
            --k;
        }
        string res;
        bool isLeadZero = true;
        for (const char &digit:st) {
            if (isLeadZero && digit == '0')
                continue;
            isLeadZero = false;
            res += digit;
        }
        return res == "" ? "0" : res;
    }
};