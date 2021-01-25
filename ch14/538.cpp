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
    TreeNode *convertBST(TreeNode *root) {
        vector<int> vals;
        vector<TreeNode *> nodes;
        inorder(root, vals, nodes);
        for (int i = 1; i < vals.size(); ++i) {
            vals[i] += vals[i - 1];
        }
        for (int i = 0; i < nodes.size(); ++i) {
            nodes[i]->val = vals[i];
        }
        return root;
    }

private:
    void inorder(TreeNode *root, vector<int> &vals, vector<TreeNode *> nodes) {
        if (!root) return;
        inorder(root->right, vals, nodes);
        vals.push_back(root->val);
        nodes.push_back(root);
        inorder(root->left, vals, nodes);
    }
};