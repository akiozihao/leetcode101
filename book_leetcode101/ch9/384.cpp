//
// Created by akio on 2021/1/11.
//
#include <vector>

using namespace std;

class Solution {
public:
    Solution(vector<int> &nums) : v(nums) {
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return v;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res = v;
        for (int i = 0; i < res.size(); ++i) {
            int t = i + rand() % (res.size() - i);
            swap(res[i], res[t]);
        }
        return res;
    }

private:
    vector<int> v;
};
// https://yjk94.wordpress.com/2017/03/17/%E6%B4%97%E7%89%8C%E7%9A%84%E6%AD%A3%E7%A1%AE%E5%A7%BF%E5%8A%BF-knuth-shuffle%E7%AE%97%E6%B3%95/
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */