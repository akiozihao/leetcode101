//
// Created by akio on 2021/1/10.
//

// least common multiple
// 最小共倍数

// greatest common divisor
// 最大公约数
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}