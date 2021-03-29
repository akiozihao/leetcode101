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
    int kthLargest(TreeNode *root, int k) {
        int result = 0;
        dfs(root, result, k);
        return result;
    }

   private:
    void dfs(TreeNode *root, int &result, int &k) {
        if (!root) return;
        dfs(root->right, result, k);
        if (!--k) result = root->val;
        dfs(root->left, result, k);
    }
};