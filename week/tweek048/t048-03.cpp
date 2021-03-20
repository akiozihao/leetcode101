#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int now = 0;
        for (int coin : coins) {
            if (coin <= now + 1)
                now += coin;
            else
                break;
        }
        return now + 1;
    }
};