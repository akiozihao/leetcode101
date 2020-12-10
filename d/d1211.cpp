//
// Created by akio on 2020/12/11.
//
#include <string>
#include <queue>
using namespace std;
class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> R,D;
        int sz = senate.size();
        for(int i=0;i<sz;++i){
            if(senate[i]=='R')
            {
                R.push(i);
            }else{
                D.push(i);
            }
        }
        while(!R.empty() && !D.empty()){
            if(R.front() < D.front()){
                D.pop();
                int t = R.front();
                R.pop();
                R.push(t + sz);
            }else{
                R.pop();
                int t = D.front();
                D.pop();
                D.push(t + sz);
            }
        }
        return R.empty()? "Dire" : "Radiant";
    }
};