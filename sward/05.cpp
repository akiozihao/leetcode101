#include <string>
using namespace std;

class Solution {
   public:
    string replaceSpace(string s) {
        int n = s.size();
        int cnt = 0;
        for (auto &c : s) {
            if (c == ' ') ++cnt;
        }
        s.resize(n + 2 * cnt);
        for (int i = n - 1, j = s.size() - 1; i < j; --i, --j) {
            if (s[i] != ' ') {
                s[j] = s[i];
            } else {
                s[j - 2] = '%';
                s[j - 1] = '2';
                s[j] = '0';
                j -= 2;
            }
        }
        return s;
    }
};