//
// Created by akio on 2020/12/5.
//
#include <vector>
#include <queue>
#include <unordered_map>
#include <numeric>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> m;
        for(const char &t:tasks)
            ++m[t];
        int maxExec = max_element(m.begin(),m.end(),[](const auto &u,const auto &v){
            return u.second < v.second;
        })->second;
        int maxCount = accumulate(m.begin(),m.end(),0,[=](int acc,const auto &u){
            return acc + (u.second == maxExec);
        });
        return max((maxExec-1)*(n+1) + maxCount,static_cast<int>(tasks.size()));
    }
};