#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int res = 0, i = 0, n = s.size();
        while (i + k <= n) {
            vector<int> cnt(26, 0);
            int mask = 0, max_idx = i;
            for (int j = i; j < n; ++j) {
                int t = s[j] - 'a';
                ++cnt[t];
                if (cnt[t] < k)
                    mask |= (1 << t);
                else
                    mask &= ~(1 << t);
                if (mask == 0) {
                    res = max(res, j - i + 1);
                    max_idx = j;
                }
            }
            i = max_idx + 1;
        }
        return res;
    }
    // 分治
    // 对于字符串s，如果存在某个字符ch，它的出现次数 (0,k)
    // ，则任何包含ch的子串都不可能满足要求
    int longestSubstring(string s, int k) {
        int n = s.size();
        return dfs(s, 0, n - 1, k);
    }

private:
    int dfs(const string &s, int l, int r, int k) {
        vector<int> cnt(26, 0);
        for (const char &ch : s) {
            ++cnt[ch - 'a'];
        }

        char split = 0;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] > 0 && cnt[i] < k) {
                split = i + 'a';
                break;
            }
        }
        if (split == 0) {
            return r - l + 1;
        }
        int i = l;
        int res = 0;
        while (i <= r) {
            while (i <= r && s[i] == split) {
                ++i;
            }
            if (i > r) break;
            int start = i;
            while (i <= r && s[i] != split) {
                ++i;
            }
            int length = dfs(s, start, i - 1, k);
            res = max(res, length);
        }
        return res;
    }
};