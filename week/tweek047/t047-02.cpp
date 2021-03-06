#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPowersOfThree(int n) {
        int k = 15;
        while (k >= 0) {
            if (pow(3, k) > n)
                --k;
            else
                {n -= pow(3, k);--k;}
            if (n == 0) return true;
            // cout << n << endl;
        }
        return n == 0;
    }
};