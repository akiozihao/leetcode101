//
// Created by akio on 2021/1/25.
//

#include <stack>
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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode *> stk;
        TreeNode *p = root;
        while (p || !stk.empty()) {
            if (p) {
                stk.push(p);
                res.insert(res.begin(), p->val);
                p = p->right;
            } else {
                p = stk.top();
                stk.pop();
                p = p->left;
            }
        }
        return res;
    }
};