//
// Created by akio on 2020/12/20.
//
#include <string>

using namespace std;

class Solution {
public:
    string reformatNumber(string number) {
        int cnt = 0;
        string number2;
        for (const char &ch:number) {
            if (ch >= '0' && ch <= '9') {
                number2 += ch;
            }
        }
        int sz = number2.size();
        string res;
        int i = 0;
        while (sz - i > 4) {
            res += number2.substr(i, 3);
            res += '-';
            i += 3;
        }
        if (sz - i == 4) {
            res += number2.substr(i, 2);
            res += '-';
            i += 2;
            res += number2.substr(i, 2);
        } else if (sz - i == 3) {
            res += number2.substr(i, 3);
        } else if (sz - i == 2) {
            res += number2.substr(i, 2);
        } else {
            res += number2.substr(i, 1);
        }
        return res;
    }
};