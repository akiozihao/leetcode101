//
// Created by akio on 2021/1/12.
//
#include <string>
#include <unordered_map>
#include <stack>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) return true;
        unordered_set<char> iset{'(', '[', '{'};
        unordered_set<char> oset{')', ']', '}'};
        unordered_map<char, char> m{
                {'}', '{',},
                {')', '('},
                {']', '['},
        };
        stack<char> st;
        for (char &c:s) {
            if (iset.count(c)) {
                st.push(c);
            } else if (oset.count(c)) {
                if (!st.empty() && m[c] == st.top()) {
                    st.pop();
                } else
                    return false;
            }
        }
        return st.empty();
    }
};