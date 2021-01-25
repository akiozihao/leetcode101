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
    void recoverTree(TreeNode *root) {
        vector<TreeNode *> list;
        vector<int> vals;
        inorder(root, list, vals);
        sort(vals.begin(), vals.end());
        for (int i = 0; i < list.size(); ++i) {
            list[i]->val = vals[i];
        }
    }

private:
    void inorder(TreeNode *node, vector<TreeNode *> &list, vector<int> &vals) {
        if (!node) return;
        inorder(node->left, list, vals);
        list.push_back(node);
        vals.push_back(node->val);
        inorder(node->right, list, vals);
    }
};