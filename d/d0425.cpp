#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    TreeNode *increasingBST(TreeNode *root) {
        TreeNode *dummy = new TreeNode(-1);
        p = dummy;
        inorder(root);
        return dummy->right;
    }

   private:
    TreeNode *p;
    void inorder(TreeNode *node) {
        if (!node) return;
        inorder(node->left);
        p->right = node;
        node->left = nullptr;
        p = node;
        inorder(node->right);
    }
};