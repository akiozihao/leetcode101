//
// Created by akio on 2021/1/28.
//
#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int> &citations) {
        int n = citations.size(), l = 0, r = n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (citations[mid] < n - mid) l = mid + 1;
            else r = mid;
        }
        return n - r;
    }
};