//
// Created by akio on 2021/1/23.
//
#include <string>
#include <vector>
#include <set>
#include <climits>

using namespace std;

class Solution {
public:
    int minCharacters(string a, string b) {
        int m = a.size(), n = b.size();
        if (m < n) {
            swap(a, b);
            swap(m, n);
        }
        vector<int> cnt1(26, 0);
        vector<int> cnt2(26, 0);
        for (char &c:a) {
            ++cnt1[c - 'a'];
        }
        for (char &c:b) {
            ++cnt2[c - 'a'];
        }
        int k = 0, cnt = 0;
        for (int i = 0; i < 26; ++i) {
            int t = min(cnt1[i], cnt2[i]);
            if (t > cnt) {
                cnt = t;
                k = i;
            }
        }
        vector<vector<int>> ab(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> ba(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (b[j] == 'a') ab[i][j] = INT_MAX;
                if (a[i] == 'z') ba[i][j] = INT_MAX;
                if (a[i] < b[j]) ab[i][j] = ab[i - 1][j - 1];
                else ab[i][j] = min(min(ab[i - 1][j], ab[i][j - 1]) + 1, INT_MAX);
                if (b[j] < a[i]) ba[i][j] = ba[i - 1][j - 1];
                else ba[i][j] = min(min(ba[i - 1][j], ba[i][j - 1]) + 1, INT_MAX);
            }
        }
        return min(ab.back().back(), min(ba.back().back(), min(n, m + n - cnt1[k] - cnt2[k])));
    }

    int minCharacters2(string a, string b) {
        vector<int> ca(26);
        vector<int> cb(26);
        for (char c:a) {
            ++ca[c - 'a'];
        }
        for (char c:b) {
            ++cb[c - 'a'];
        }
        vector<int> sa(27);
        vector<int> sb(27);
        for (int i = 0; i < 26; ++i) {
            sa[i + 1] = sa[i] + ca[i];
        }
        for (int i = 0; i < 26; ++i) {
            sb[i + 1] = sb[i] + cb[i];
        }
        int res = (1 << 30);
        for (int i = 0; i < 26; ++i) {
            res = min(res, sa[26] + sb[26] - ca[i] - cb[i]);
        }
        auto sum = [](vector<int> &s, int a, int b) {
            return s[b + 1] - s[a];
        };
        for (int i = 0; i < 25; ++i) {
            res = min(res, sum(sa, i + 1, 25) + sum(sb, 0, i));
            res = min(res, sum(sb, i + 1, 25) + sum(sa, 0, i));
        }
        return res;
    }
};