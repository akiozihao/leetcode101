//
// Created by akio on 2021/1/23.
//
#include <vector>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
        if (to_delete.empty()) return {root};
        vector<TreeNode *> res;
        unordered_set<int> st{to_delete.begin(), to_delete.end()};
        root = helper(res, root, st);
        if (root)
            res.push_back(root);
        return res;
    }

private:
    TreeNode *helper(vector<TreeNode *> &res, TreeNode *node, const unordered_set<int> &st) {
        if (!node) return node;
        node->left = helper(res, node->left, st);
        node->right = helper(res, node->right, st);
        if (st.count(node->val)) {
            if (node->left) {
                res.push_back(node->left);
            }
            if (node->right) {
                res.push_back(node->right);
            }
            node = nullptr;
        }
        return node;
    }
};