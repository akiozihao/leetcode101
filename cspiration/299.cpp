//
// Created by akio on 2021/1/27.
//
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> cnt(10, 0);
        int a = 0, b = 0;
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) ++a;
            else {
                if (cnt[secret[i] - '0']++ < 0) ++b;
                if (cnt[guess[i] - '0']-- > 0) ++b;
            }
        }
        return to_string(a) + 'A' + to_string(b) + 'B';
    }
};