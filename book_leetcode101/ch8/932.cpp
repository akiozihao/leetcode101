//
// Created by akio on 2020/11/14.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> res{1};
        while (res.size() < N) {
            vector<int> t;
            for (int num:res) {
                if (num * 2 - 1 <= N) t.push_back(num * 2 - 1);
            }
            for (int num:res) {
                if (num * 2 <= N) t.push_back(num * 2);
            }
            res = t;
            for (auto i:res) {
                cout << i << ' ';
            }
            cout << endl;
        }
        return res;
    }
};

int main() {
    Solution s;
    s.beautifulArray(10);
}