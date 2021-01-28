//
// Created by akio on 2021/1/11.
//
#include <string>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int remain = 0;
        int p1 = num1.size() - 1, p2 = num2.size() - 1;
        string res;
        while (p1 >= 0 || p2 >= 0) {
            int t1 = p1 >= 0 ? num1[p1] - '0' : 0;
            int t2 = p2 >= 0 ? num2[p2] - '0' : 0;
            int t = remain + t1 + t2;
            res += t % 10 + '0';
            remain = t / 10;
            --p1;
            --p2;
        }
        if (remain) {
            res += '1';
        }
        return {res.rbegin(), res.rend()};
    }
};