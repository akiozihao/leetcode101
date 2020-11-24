//
// Created by akio on 2020/11/8.
//
#include <set>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &inventory, int orders) {
        multiset<int> mst{inventory.begin(), inventory.end()};
        long long res = 0;
        while (orders) {
            auto p = --mst.end();
            long long val = *p;
            if (mst.size() == 1) {
                res += (val + (val - orders + 1)) * orders / 2;
                break;
            }
            res += val;
            mst.erase(p);
            mst.insert(val - 1);
            --orders;
        }
        return int(res % (1000000000 + 7));
    }
};

int main() {
    vector<int> i{1000000000};
    Solution s;
    cout << s.maxProfit(i, 1000000000);
}