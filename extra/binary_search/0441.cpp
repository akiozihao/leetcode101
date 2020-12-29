//
// Created by akio on 2020/12/29.
//

class Solution {
public:
    int arrangeCoins(int n) {
        if(n<=1) return n;
        long low = 1,high = n;
        while(low < high){
            long mid = low + (high-low)/2;
            // 找第一个前mid项和大于n的行
            if(mid*(mid+1)/2 <= n) low = mid + 1;
            else high = mid;
        }
        // 那么往前一行一定小于等于n
        return high-1;
    }
};