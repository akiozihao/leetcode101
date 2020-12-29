//
// Created by akio on 2020/12/26.
//
#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>
using namespace std;
using namespace std;
bool cmp(const string lhs,const string rhs){
    for(int i=0;i<lhs.size();++i){
        if(lhs[i]!=rhs[i]) return lhs[i] > rhs[i];
    }
    return lhs.back() > rhs.back();
}
class Solution {
public:
    string maximumBinaryString(string binary) {
        if(binary.empty() || binary.size() < 2) return binary;
        unordered_set<string> st;
        st.insert(binary);
        string res = binary;
        helper(binary,st,res);
        cout << st.size() << endl;
        return res;
    }

private:
    void helper(const string &binary,unordered_set<string> &st,string &res){
        for(int i=0;i<binary.size()-1;++i){
            if(binary.substr(i,2)=="00"){
                string t = binary;
                t[i] = '1';
                t[i+1] ='0';
                if(!st.count(t)){
                    st.insert(t);
                    if(cmp(t,res)) res = t;
                    helper(t,st,res);
                }
            }
            else if(binary.substr(i,2)=="10"){
                string t = binary;
                t[i] = '0';
                t[i+1] ='1';
                if(!st.count(t)){
                    st.insert(t);
                    if(cmp(t,res)) res = t;
                    helper(t,st,res);
                }
            }
        }
    }
};

int main() {
    Solution s;
    cout << s.maximumBinaryString("00111101100000110010");
}