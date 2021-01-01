//
// Created by akio on 2020/12/29.
//

#include <vector>

using namespace std;

// 查找和目标值完全相等的数
int find(vector<int> &nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) left = mid + 1;
        else right = mid;
    }
    return -1;
}
// 二分查找的写法并不唯一，主要可以变动的地方有四处：
// 第一处是 right 的初始化，可以写成 nums.size() 或者 nums.size() - 1;
// 第二处是 left 和 right 的关系，可以写成 left < right 或者 left <= right;
// 第三处是更新 right 的赋值，可以写成 right = mid 或者 right = mid - 1;
// 第四处是最后的返回值，可以写成 left , right 或者 right - 1;

// 如果 right 初始化为 nums.size(),那么必须用 left < right,
// 而最后的 right 的赋值必须用 right = mid。

// 如果 right 初始化为 nums.size() - 1,那么必须用 left <= right,
// 而最后的 right 的赋值必须用 right = mid - 1。

// 查找第一个不小于目标值的数，可变形为查找最后一个小于目标值的数
// 这是比较常见的一类，因为要查找的目标值不一定会在数组中出现，也有可能和目标值相同的数在数组中存在多个，
// 那么在这种情况下 nums[mid] == target 就不需要了。
// 对应 lower_bound
int find2(vector<int> &nums,int target){
    int left = 0,right =nums.size();
    while(left < right){
        int mid = left + (right-left)/2;
        if(nums[mid]<target) left = mid + 1;
        else right = mid;
    }
    // 这个地方返回 left 还是 right 都是正确的。while(left < right) 的结束条件就是left==right
    return right;
}

// 查找第一个大于目标值的数，可变形为查找最后一个不大于目标值的数
// 对应 upper_bound
// 在找到第一个大于目标值的数的位置后，往前一位则是最后一个不大于目标值的位置。
int find3(vector<int>&nums,int target){
    int left = 0,right = nums.size();
    while(left<right){
        int mid = left + (right-left)/2;
        if(nums[mid]<=target) left = mid + 1;
        else right =mid;
    }
    return right;
}
// 与前一种相比只是加了一个等于号就改变了搜索的方向，这样会在数组中有很多和目标值相同的情况下
// 返回最后一个相同的数字的下一个位置。

// 从排除法的角度来考虑，nums[mid] <= target 时 left = mid + 1 使得当nums[mid] == target
// 时 left 也会向右移动从而排除掉等于target的位置，最终会得到大于 target 的第一个位置

//