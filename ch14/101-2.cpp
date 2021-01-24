//
// Created by akio on 2021/1/23.
//
#include <queue>

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
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        queue<TreeNode *> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        while (!q1.empty() && !q2.empty()) {
            TreeNode *n1 = q1.front();
            q1.pop();
            TreeNode *n2 = q2.front();
            q2.pop();
            if (!n1 && !n2) continue;
            if (!n1 || !n2) return false;
            if (n1->val != n2->val) return false;
            q1.push(n1->left);
            q1.push(n1->right);
            q2.push(n2->right);
            q2.push(n2->left);
        }
        return true;
    }
};