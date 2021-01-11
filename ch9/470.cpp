//
// Created by akio on 2021/1/11.
//
int rand7();
// 拒绝采样

class Solution {
public:
    int rand10() {
        while (true) {
            int row = rand7();
            int col = rand7();
            int idx = (row - 1) * 7 + col;
            if (idx <= 40) return idx % 10 + 1;
        }
    }
};