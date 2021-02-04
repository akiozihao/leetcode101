//
// Created by akio on 2021/2/5.
//
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int> diff(n);
        for (int i = 0; i < n; ++i) {
            diff[i] = abs(s[i] - t[i]);
        }
        vector<int> accdiff(n + 1, 0);
        for (int i = 1; i < n + 1; ++i) {
            accdiff[i] = accdiff[i - 1] + diff[i - 1];
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            // 最后一位使得cost < maxCost,即第一位使得cost大于cost的位减 1;
            int l = i, r = n;
            while (l < r) {
                int mid = l + (r - l) / 2;
                int c = accdiff[mid + 1] - accdiff[i];
                if (c <= maxCost) l = mid + 1;
                else r = mid;
            }
            res = max(res, r - i);
        }
        return res;
    }

    int equalSubstring2(string s, string t, int maxCost) {
        int n = s.size();
        vector<int> diff(n);
        for (int i = 0; i < n; ++i) {
            diff[i] = abs(s[i] - t[i]);
        }
        int l = 0, r = 0, sum = 0, res = 0;
        while (r < n) {
            sum += diff[r];
            while (sum > maxCost) {
                sum -= diff[l++];
            }
            res = max(res, r - l + 1);
            ++r;
        }
        return res;
    }

};

int main() {
    Solution s;
    s.equalSubstring("abcd", "bcdf", 3);
}