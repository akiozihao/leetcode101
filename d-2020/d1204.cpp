//
// Created by akio on 2020/12/4.
//
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    bool isPossible(vector<int> &nums) {
        unordered_map<int, priority_queue<int, vector<int>, greater<>>> m;
        for (int &num:nums) {
            if (m.find(num) == m.end()) {
                m[num] = priority_queue<int, vector<int>, greater<>>();
            }
            if (m.find(num - 1) != m.end()) {
                int preLen = m[num - 1].top();
                m[num - 1].pop();
                if (m[num - 1].empty())
                    m.erase(num - 1);
                m[num].push(preLen + 1);
            } else
                m[num].push(1);
        }
        for (auto &it : m) {
            auto pq = it.second;
            if (pq.top() < 3)
                return false;
        }
        return true;
    }

    bool isPossible2(vector<int> &nums) {
        unordered_map<int, int> cnt, subs;
        for (int &num:nums) {
            ++cnt[num];
        }
        for(int &num:nums){
            if(!cnt[num]) continue;
            else if(subs[num-1]){
                --cnt[num];
                --subs[num-1];
                ++subs[num];
            }else if(cnt[num+1] && cnt[num+2]){
                --cnt[num];
                --cnt[num+1];
                --cnt[num+2];
                ++subs[num+2];
            }else
                return false;
        }
        return true;
    }

};

