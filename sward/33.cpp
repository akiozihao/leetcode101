#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool verifyPostorder(vector<int>& postorder) {
        return helper(postorder, 0, postorder.size() - 1);
    }

   private:
    bool helper(vector<int>& posterorder, int l, int r) {
        if (l >= r) return true;
        int mid = l;
        int root = posterorder[r];
        while (posterorder[mid] < root) {
            ++mid;
        }
        int temp = mid;
        while (temp < r) {
            if (posterorder[temp++] < root) return false;
        }
        return helper(posterorder, l, mid - 1) &&
               helper(posterorder, mid, r - 1);
    }
};