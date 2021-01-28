//
// Created by akio on 2021/1/25.
//
#include <vector>
#include <stack>

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
    vector<int> preorderTraversal(TreeNode *root) {
        if (!root) return {};
        vector<int> res;
        stack<TreeNode *> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode *node = stk.top();
            stk.pop();
            res.push_back(node->val);
            if (node->right) {
                stk.push(node->right);
            }
            if (node->left) {
                stk.push(node->left);
            }
        }
        return res;
    }

    vector<int> preorderTraversal2(TreeNode *root) {
        vector<int> res;
        if (!root) return res;
        TreeNode *p = root;
        stack<TreeNode *> stk;
        while (p || !stk.empty()) {
            if (p) {
                stk.push(p);
                res.push_back(p->val);
                p = p->left;
            } else {
                p = stk.top();
                stk.pop();
                p = p->right;
            }
        }
        return res;
    }

};