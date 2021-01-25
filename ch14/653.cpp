//
// Created by akio on 2021/1/25.
//
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool findTarget(TreeNode *root, int k) {
        vector<int> v;
        inorder(root, v);
        int l = 0, r = v.size() - 1;
        while (l < r) {
            if (v[l] + v[r] == k) return true;
            else if (v[l] + v[r] > k) --r;
            else ++l;
        }
        return false;
    }

private:
    void inorder(TreeNode *node, vector<int> &v) {
        if(!node) return;
        inorder(node->left,v);
        v.push_back(node->val);
        inorder(node->right,v);
    }
};