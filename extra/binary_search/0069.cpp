//
// Created by akio on 2021/1/1.
//
#include <vector>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        if(x<=1) return x;
        int l = 0,r = x;
        while(l<r){
            long mid= l + (r-l)/2;
            if(mid * mid <=x ) l = mid + 1;
            else r = mid;
        }
        return r-1;
    }
};