//
// Created by akio on 2020/11/22.
//
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int waysToMakeFair(vector<int> &nums) {
        int sz= nums.size();
        if(sz==1) return 1;
        vector<int> odd(sz, 0);
        vector<int> even(sz, 0);
        int s_odd = 0, s_even = 0;
        for (int i = sz - 1; i >= 0; --i) {
            if (i % 2 == 0) {
                s_even += nums[i];
                even[i] = s_even;
            } else {
                s_odd += nums[i];
                odd[i] = s_odd;
            }
        }
        for(int i:odd){
            cout << i << ' ';
        }
        cout << endl;
        for(int i:even){
            cout << i << ' ';
        }
        cout << endl;
        int cnt = 0;
        for (int i = 0; i < sz; ++i) {
            if (i % 2 == 0) {
                if (even[0] - even[i] + (i + 1 < sz ? odd[i + 1] : 0) ==
                    odd[1] - (i + 1 < sz ? odd[i + 1] : 0) + (i + 2 < sz ? even[i + 2] : 0))
                    ++cnt;
            } else {
                if (even[0] - (i + 1 < sz ? even[i + 1] : 0) + (i + 2 < sz ? odd[i + 2] : 0) ==
                    odd[1] - odd[i] + (i + 1 < sz ? even[i + 1] : 0))
                    ++cnt;
            }
        }
        return cnt;
    }
};

int main() {
    Solution s;
    vector<int> v{1};
    cout << s.waysToMakeFair(v);
}