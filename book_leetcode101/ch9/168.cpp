//
// Created by akio on 2021/1/11.
//
#include <string>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while (n) {
            --n;
            res += n % 26 + 'A';
            n /= 26;
        }
        return {res.rbegin(), res.rend()};
    }
};