#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxValue(int n, int index, int maxSum) {
        int l = index, r = index;
        int res = 1;
        int rest = maxSum - n;
        while (l > 0 || r < n - 1) {
            int len = r - l + 1;
            if (rest >= len) {
                rest -= len;
                ++res;
                l = max(0, l - 1);
                r = min(n - 1, r + 1);
            } else
                break;
        }
        res += rest / n;
        return res;
    }
};