#include <vector>
using namespace std;
class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0], cnt = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == candidate)
                ++cnt;
            else {
                --cnt;
                if (cnt < 0) {
                    candidate = nums[i];
                    cnt = 1;
                }
            }
        }
        return candidate;
    }
    // 超过1/3
    vector<int> majorityElement2(vector<int>& nums) {
        int n = nums.size();
        int cand1 = 0, cand2 = 0, cnt1 = 0, cnt2 = 0;
        for (auto x : nums) {
            if (cand1 == x) {
                ++cnt1;
            } else if (cand2 == x) {
                ++cnt2;
            } else if (!cnt1) {
                cand1 = x;
                cnt1 = 1;
            } else if (!cnt2) {
                cand2 = x;
                cnt2 = 1;
            } else {
                --cnt1;
                --cnt2;
            }
        }
        cnt1 = cnt2 = 0;
        for (auto x : nums) {
            if (x == cand1)
                ++cnt1;
            else if (x == cand2)
                ++cnt2;
            ;
        }
        vector<int> res;
        if (cnt1 > n / 3) res.push_back(cand1);
        if (cnt2 > n / 3) res.push_back(cand2);
        return res;
    }
};