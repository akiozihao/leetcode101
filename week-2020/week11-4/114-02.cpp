//
// Created by akio on 2020/11/29.
//
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> mostCompetitive(vector<int> &nums, int k) {
        int sz = nums.size();
        if (sz == k) return nums;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (k > 0 && (res.empty() || res.back() <= nums[i])) {

            } else {
                while(!res.empty() && res.back() > nums[i]  && (sz - i) >=k + 1){
                    res.pop_back();
                    ++k;
                }
            }
            if(k>0){
                res.push_back(nums[i]);
                --k;
            }
        }
        return res;
    }
};

int main() {
    vector<int> a{84,10,71,23,66,61,62,64,34,41,80,25,91,43,4,75,65,13,37,41,46,90,55,8,85,61,95,71};
    Solution s;
    vector<int> r = s.mostCompetitive(a,24);
    for(int i:r){
        cout << i <<' ';
    }
}