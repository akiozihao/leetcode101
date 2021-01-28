//
// Created by akio on 2020/11/14.
//
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for (int i = 0; i < input.size(); ++i) {
            char ch = input[i];
            if (ch == '+' || ch == '-' || ch == '*') {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));
                for (auto l:left) {
                    for (auto r:right) {
                        switch (ch) {
                            case '+': {
                                res.push_back(l + r);
                                break;
                            }
                            case '-': {
                                res.push_back(l - r);
                                break;
                            }
                            case '*': {
                                res.push_back(l * r);
                                break;
                            }
                        }
                    }
                }
            }
        }
        if(res.empty()) res.push_back(stoi(input));
        return res;
    }
};