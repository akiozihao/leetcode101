//
// Created by akio on 2020/11/16.
//
#include <vector>
#include <list>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a[0] == b[0]) return a[1] <= b[1];
            return a[0] > b[0];
        });
        list<vector<int>> temp;

        for (auto &p:people) {
            auto ptr = temp.begin();
            advance(ptr, p[1]);
            temp.insert(ptr, p);
        }
        return {temp.begin(), temp.end()};
    }
};