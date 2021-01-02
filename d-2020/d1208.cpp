//
// Created by akio on 2020/12/8.
//
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> res;
        helper(S, S.size(), res, 0, 0, 0);
        return res;
    }

private:
    bool helper(const string &S, int sz, vector<int> &res, int idx, long long sum, int prev) {
        if (idx == S.size())
            return res.size() >= 3;
        long long curr = 0;
        for (int i = idx; i < sz; ++i) {
            if (i > idx && S[idx] == '0')
                break;
            curr = curr * 10 + S[i] - '0';
            if (curr > INT_MAX)
                break;
            if (res.size() >= 2) {
                if (curr < sum)
                    continue;
                else if (curr > sum)
                    break;
            }
            res.push_back(curr);
            if(helper(S,sz,res,i+1,prev+curr,curr))
                return true;
            res.pop_back();
        }
        return false;
    }
};