#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || preorder.size() != inorder.size())
            return nullptr;
        int m = preorder.size();
        return buildTree(preorder, 0, m - 1, inorder, 0, m - 1);
    }

   private:
    TreeNode* buildTree(vector<int>& preorder, int pl, int pr,
                        vector<int>& inorder, int il, int ir) {
        if (pl > pr || il > ir) return nullptr;
        TreeNode* node = new TreeNode(preorder[pl]);
        int i = il;
        for (; i <= ir; ++i) {
            if (inorder[i] == preorder[pl]) break;
        }
        int len = i - il;
        node->left = buildTree(preorder, pl + 1, pl + len, inorder, il, i - 1);
        node->right = buildTree(preorder, pl + len + 1, pr, inorder, i + 1, ir);
        return node;
    }
};