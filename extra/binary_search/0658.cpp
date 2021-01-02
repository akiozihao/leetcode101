//
// Created by akio on 2021/1/2.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        vector<int> res = arr;
        while (res.size() > k) {
            if (x - res.front() <= res.back() - x) {
                res.pop_back();
            } else {
                res.erase(res.begin());
            }
        }
        return res;
    }

    vector<int> findClosestElements2(vector<int> &arr, int k, int x) {
        int left = 0,right = arr.size()-k;
        while(left < right){
            int mid = left + (right-left)/2;
            if(x - arr[mid] > arr[mid+k] - x) left = mid + 1;
            else right = mid;
        }
        return {arr.begin()+right,arr.begin() + right + k};
    }
};