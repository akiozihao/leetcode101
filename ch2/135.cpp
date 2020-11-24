//
// Created by akio on 2020/10/10.
//

#include <vector>
#include <numeric>

using namespace std;

int candy(vector<int> &children){
    int sz = children.size();
    vector<int> candies(sz,1);
    for(int i=1;i<sz;++i){
        if(children[i]>children[i-1]) candies[i] = candies[i-1]+1;
    }
    for(int i=sz-1;i>0;--i){
        if(children[i]<children[i-1]) candies[i-1] = max(candies[i]+1,candies[i-1]);
    }
    return accumulate(candies.begin(),candies.end(),0);
}