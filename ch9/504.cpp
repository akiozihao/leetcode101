//
// Created by akio on 2021/1/11.
//
#include <string>

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        bool is_neg = num < 0;
        if (is_neg) num = -num;
        string res;
        while (num) {
            int a = num / 7, b = num % 7;
            res = to_string(b) + res;
            num = a;
        }
        return is_neg ? "-" + res : res;
    }
};

int main() {
    Solution s;
    s.convertToBase7(7);
}