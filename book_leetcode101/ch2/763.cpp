//
// Created by akio on 2020/10/10.
//

#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;
vector<int> partitionLabels(string S) {
    vector<int> last(26,0);
    for(int i=0;i<S.size();++i){
        last[S[i]-'a'] = i;
    }
    int j=0,anchor=0;
    vector<int> res;
    for(int i=0;i<S.size();++i){
        j = max(j,last[S[i]-'a']);
        if(i==j){
            res.push_back(i-anchor+1);
            anchor = i+1;
        }
    }
    return res;
}

vector<int> partitionLabels2(string S) {
    if (S.empty()) return {};
    unordered_map<char, vector<int>> m;
    for (int i = 0; i < S.size(); ++i) {
        if (m[S[i]].empty()) {
            m[S[i]].push_back(i);
            m[S[i]].push_back(i);
        } else m[S[i]].back() = i;
    }
    vector<vector<int>> vec;
    vec.reserve(m.size());
    for (auto &i : m) {
        vec.push_back(i.second);
    }
    sort(vec.begin(), vec.end(), [](vector<int> a, vector<int> b) {
        return a[0] < b[0];
    });
    vector<int> res;
    vector<int> tmp = vec[0];
    vector<vector<int>> vec2;
    for (int i = 1; i < vec.size(); ++i) {
        if (vec[i][0] < tmp[1]) {
            tmp[1] = max(vec[i][1],tmp[1]);
        } else {
            vec2.push_back(tmp);
            tmp = vec[i];
        }
    }
    vec2.push_back(tmp);
    res.reserve(vec2.size());
    for (auto &i : vec2) {
        res.push_back(i[1]-i[0]+1);
    }
    return res;
}

int main() {
    partitionLabels("ababcbacadefegdehijhklij");
}