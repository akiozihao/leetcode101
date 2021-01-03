//
// Created by akio on 2020/11/15.
//
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        if (m != n) return false;
        vector<int> cnta(26, 0);
        vector<int> cntb(26, 0);
        for (int i = 0; i < m; ++i) {
            ++cnta[word1[i] - 'a'];
            ++cntb[word2[i] - 'a'];
        }
        multiset<int> diffa, diffb;
        for (int i = 0; i < cnta.size(); ++i) {
            if (!cnta[i] && !cntb[i])
                continue;
            if (cnta[i] && cntb[i]) {
                if (cnta[i] != cntb[i]) {
                    diffa.insert(cnta[i]);
                    diffb.insert(cntb[i]);
                }
            }else
                return false;
        }
        for (int i:diffa) {
            if (diffb.count(i)) {
                diffa.erase(diffa.find(i));
                diffb.erase(diffb.find(i));
            } else
                return false;
        }
        return diffa.empty() && diffb.empty();
    }
};