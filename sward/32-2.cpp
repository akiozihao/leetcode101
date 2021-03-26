#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> v;
            while (sz) {
                auto n = q.front();
                q.pop();
                v.push_back(n->val);
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
                --sz;
            }
            res.push_back(v);
        }
        return res;
    }
};