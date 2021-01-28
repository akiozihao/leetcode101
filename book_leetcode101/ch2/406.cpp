//
// Created by akio on 2020/10/10.
//
#include <vector>
#include <algorithm>
#include <iostream>
#include <list>

using namespace std;

vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
    if (people.empty()) return {};
    vector<vector<int>> res;
    sort(people.begin(), people.end(), [](vector<int> a, vector<int> b) {
        if (a[0] == b[0]) return a[1] <= b[1];
        else return a[0] > b[0];
    });
    int len = people.size();
    list<vector<int>> tmp;
    for (int i = 0; i < len; ++i) {
        auto pos = tmp.begin();
        advance(pos, people[i][1]);
        tmp.insert(pos, people[i]);
    }
    return vector<vector<int>>(tmp.begin(), tmp.end());
}

vector<vector<int>> reconstructQueue2(vector<vector<int>> &people) {
    if (people.empty()) return {};
    sort(people.begin(), people.end(), [](vector<int> a, vector<int> b) {
        if (a[1] == b[1]) return a[0] < b[0];
        else return a[1] < b[1];
    });
    vector<vector<int>> res;
    res.push_back(people[0]);
    for (int i = 1; i < people.size(); ++i) {
        if (people[i][1] == res.back()[1]) res.push_back(people[i]);
        else {
            int count = 0;
            auto ptr = res.begin();
            while (ptr != res.end()) {
                if ((*ptr)[0] >= people[i][0]) ++count;
                if (count == people[i][1]) {
                    ++ptr;
                    while (ptr != res.end() && people[i][0] >= (*ptr)[0]) ++ptr;
                    res.insert(ptr, people[i]);
                    break;
                }
                ++ptr;
            }
        }
    }
    return res;
}

int main() {

    vector<vector<int>> vv;
    vv.push_back({7, 0});
    vv.push_back({4, 4});
    vv.push_back({7, 1});
    vv.push_back({5, 0});
    vv.push_back({6, 1});
    vv.push_back({5, 2});

    auto res = reconstructQueue(vv);


}