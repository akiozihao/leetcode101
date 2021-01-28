//
// Created by akio on 2020/10/16.
//

#include <vector>

using namespace std;

void bubble_sort(vector<int> &nums, int n) {
    bool swapped;
    for (int i = 1; i < n; ++i) {
        for (int j = i; j < n - i + 1; ++j) {
            if(nums[j] < nums[j-1]){
                swap(nums[j],nums[j-1]);
                swapped=true;
            }
        }
        if(!swapped)
            break;
    }
}