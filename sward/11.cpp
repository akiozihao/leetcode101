#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minArray(vector<int>& numbers) {
        int n = numbers.size();
        int l = 0, r = n-1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (numbers[m] > numbers[r]) {
                l = m + 1;
            } else if (numbers[m] < numbers[r])
                r = m;
            else
                --r;
        }
        return numbers[r];
    }
};