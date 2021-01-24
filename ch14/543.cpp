//
// Created by akio on 2021/1/23.
//
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode *root) {
        int res = 0;
        maxDepth(root, res);
        return res;
    }

private:
    int maxDepth(TreeNode *node, int &res) {
        if (!node) return 0;
        int left = maxDepth(node->left, res);
        int right = maxDepth(node->right, res);
        res = max(res, left + right);
        return max(left, right) + 1;
    }
};