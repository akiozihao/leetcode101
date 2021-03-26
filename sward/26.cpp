struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
   public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!A || !B) return false;
        return isSame(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

   private:
    bool isSame(TreeNode* a, TreeNode* b) {
        if (!b) return true;
        if (!a) return false;
        if (a->val != b->val) return false;
        return isSame(a->left, b->left) && isSame(a->right, b->right);
    }
};