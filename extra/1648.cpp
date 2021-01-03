//
// Created by akio on 2021/1/3.
//
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        int MOD = 1e9+7;
        sort(inventory.begin(), inventory.end());
        int len = inventory.size(), t = orders, cnt = 1;
        for(int i = len - 1; i >= 1; --i){
            if(t > (inventory[i] - inventory[i-1]) * cnt){
                t -= (inventory[i] - inventory[i-1]) * cnt;
                ++cnt;
            }
            else break;
        }
        long long  res = 0, x = t/cnt;
        int r = t % cnt;
        res = (inventory[len-cnt] - x)*r % MOD;   //剩余部分特殊处理
        for(int i = len - cnt; i < len; ++i){     //遍历累加到res中
            if(i > len-cnt)
                x += inventory[i] - inventory[i-1];
            //等差数列求和：inventory[i] + inventory[i]-1  + ... + (inventory[i]-x+1)
            long long k = (2 * inventory[i] - x + 1) * x / 2;
            res = (res % MOD + k % MOD) % MOD;
        }
        return res;
    }
};
