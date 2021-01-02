//
// Created by akio on 2020/12/27.
//
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m;
        int sz = s.size();
        for(int i=0;i<sz;++i){
            if(m.count(s[i])){
                if(m[s[i]] != t[i]) return false;
            }else{
                m[s[i]] = t[i];
            }
        }
        return true;
    }
};