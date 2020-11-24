//
// Created by akio on 2020/10/10.
//
#include <vector>

using namespace std;


bool canPlaceFlowers(vector<int> &flowerbed, int n) {
    if (flowerbed.size() <= n) return false;
    int sz = flowerbed.size();
    for (int i = 0; i < sz; ++i) {
        if (n == 0) return true;
        else if (flowerbed[i] == 0){
            if((i==0 || flowerbed[i-1]==0) && (i==sz-1 || flowerbed[i+1]==0)){
                flowerbed[i]=1;
                --n;
            }
        }
    }
    return n==0;
}
