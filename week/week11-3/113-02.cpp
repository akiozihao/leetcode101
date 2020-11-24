//
// Created by akio on 2020/11/22.
//
#include <stack>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string getSmallestString(int n, int k) {
        string res;
        helper(res, n, k);
        return res;
    };

private:
    void helper(string &res, int n, int k) {
        if (n == 1) {
            res += 'a' + k - 1;
            return;
        }
        if (k - 1 <= (n - 1) * 26) {
            res += 'a';
            helper(res, n - 1, k - 1);
        } else {
            int ti = k - (n - 1) * 26;
            char t = 'a' + ti - 1;
            res += t;
            helper(res, n - 1, k - ti);
        }
        res;
    }
};

int main() {
    Solution s;
    cout << s.getSmallestString(5, 73);
}