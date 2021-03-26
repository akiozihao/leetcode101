struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isSymmetric(root, root);
    }

   private:
    bool isSymmetric(TreeNode* n1, TreeNode* n2) {
        if (!n1 && !n2) return true;
        if (!n1 || !n2) return false;
        if (n1->val != n2->val) return false;
        return isSymmetric(n1->left, n2->right) &&
               isSymmetric(n1->right, n2->left);
    }
};