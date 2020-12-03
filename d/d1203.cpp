//
// Created by akio on 2020/12/3.
//
#include <vector>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        vector<int> vec(n+1,1);
        int res = 0;
        for(int i=2;i<n;++i){
            if(vec[i]){
                ++res;
                if((long long) i * i < n){
                    for(int j=i*i;j<n;j+=i){
                        vec[j] = 0;
                    }
                }
            }
        }
        return res;
    }
};