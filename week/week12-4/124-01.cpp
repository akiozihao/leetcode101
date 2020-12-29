//
// Created by akio on 2020/12/27.
//
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool halvesAreAlike(string s) {
        vector<int> cnt(26,0);
        unordered_set<char> st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        st.insert('A');
        st.insert('E');
        st.insert('I');
        st.insert('O');
        st.insert('U');
        int cnt1=0,cnt2=0;
        int gap = s.size()/2;
        for(int i=0;i<s.size();++i){
            if(st.count(s[i])){
                if(i<gap) ++cnt1;
                else ++cnt2;
            }
        }
        return cnt1==cnt2;
    }
};