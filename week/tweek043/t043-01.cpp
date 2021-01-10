//
// Created by akio on 2021/1/9.
//

class Solution {
public:
    int totalMoney(int n) {
        int week = n / 7;
        int remain = n % 7;
        return week * 28 + week * (week + 1) * 7 +
    }
};