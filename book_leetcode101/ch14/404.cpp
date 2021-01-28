//
// Created by akio on 2021/1/25.
//
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode *root) {
        if (!root) return false;
        queue<TreeNode *> q;
        queue<bool> flag;
        q.push(root);
        flag.push(false);
        int res = 0;
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            bool f = flag.front();
            flag.pop();
            if (!node->left && !node->right && f) {
                res += node->val;
            }
            if (node->left) {
                q.push(node->left);
                flag.push(true);
            }
            if (node->right) {
                q.push(node->right);
                flag.push(false);
            }
        }
        return res;
    }
};