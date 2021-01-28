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
    TreeNode *increasingBST(TreeNode *root) {
        vector<TreeNode *> v;
        stack<TreeNode *> st;
        TreeNode *p = root;
        while (p || !st.empty()) {
            if (p) {
                st.push(p);
                p = p->left;
            } else {
                p = st.top();
                st.pop();
                v.push_back(p);
                p = p->right;
            }
        }
        for (int i = 0; i < v.size(); ++i) {
            v[i]->left = nullptr;
            if (i > 0) {
                v[i - 1]->right = v[i];
            }
            if (i == v.size() - 1) v[i]->right = nullptr;
        }
        return v[0];
    }
};