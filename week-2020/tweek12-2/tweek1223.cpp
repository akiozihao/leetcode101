//
// Created by akio on 2020/12/26.
//
#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;
using namespace std;


class Solution {
public:
    string maximumBinaryString(string binary) {
        int n = binary.size();
        int ones = 0;
        bool flag = false;
        for (int i = 0; i < n; ++i) {
            if (binary[i] == '0') flag = true;
            if (flag && binary[i] == '1') ones++;
        }
        if (!flag) return binary; // 全是 1

        string res(n, '1');
        res[n - ones - 1] = '0';
        return res;
    }
};