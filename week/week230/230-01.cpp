#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        if(items.empty()) return 0;
        int res = 0;
        int find;
        if(ruleKey=="type") find=0;
        else if(ruleKey=="color") find=1;
        else find=2;
        for(auto item:items){
            if(item[find]==ruleValue) ++res;
        }
        return res;
    }
};