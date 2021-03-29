#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
   public:
    bool isBalanced(TreeNode *root) { return helper(root) != -1; }

   private:
    int helper(TreeNode *node) {
        if (!node) return 0;
        int left = helper(node->left);
        if (left == -1) return -1;
        int right = helper(node->right);
        if (right == -1) return -1;
        if (abs(right - left) > 1) return -1;
        return 1 + max(left, right);
    }
};