//
// Created by akio on 2021/2/9.
//
#include <bits/stdc++.h>

using namespace std;

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {

    }

    void addNum(int val) {
        if (m.empty()) {
            m[val] = val;
            return;
        }
        auto it = m.lower_bound(val); // 第一个大于等于val的key
        if (it != m.end()) {
            int start = it->first, end = it->second;
            if (start == val) // 直接合并
                return;
            else if (val == start - 1) { // 和start挨着，判断是否能和前面的合并
                if (it != m.begin()) {
                    --it;
                    int preStart = it->first;
                    int preEnd = it->second;
                    if (preEnd + 1 == val) {
                        m.erase(start);
                        m[preStart] = end;
                    } else {
                        m.erase(start);
                        m[val] = end;
                    }
                } else {
                    m.erase(start);
                    m[val] = end;
                }
            } else { // val 不能和it合并
                if (it != m.begin()) {
                    --it;
                    int preStart = it->first;
                    int preEnd = it->second;
                    if (preEnd + 1 == val) {
                        m[preStart] = val;
                    } else if (preEnd + 1 < val) {
                        m[val] = val;
                    }
                } else {
                    m[val] = val;
                }
            }
        } else { //  后面没有大于等于val的了
            --it;
            int preStart = it->first;
            int preEnd = it->second;
            if (preEnd + 1 == val) {
                m[preStart] = val;
            } else if (preEnd + 1 < val) {
                m[val] = val;
            }
        }
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (auto &p:m) {
            res.push_back({p.first, p.second});
        }
        return res;
    }

private:
    map<int, int> m;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */