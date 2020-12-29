//
// Created by akio on 2020/12/29.
//

class Solution {
public:
    bool isPerfectSquare(int num) {
        long  left = 0,right = num;
        while(left < right){
            long mid = left + (right-left)/2;
            // 找第一个大于等于num的完全平方数
            if(mid*mid<num) left = mid + 1;
            else right = mid;
        }
        return num == right * right;
    }
};