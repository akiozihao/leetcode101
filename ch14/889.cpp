//
// Created by akio on 2021/1/25.
//

#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post) {
        return helper(pre, 0, pre.size() - 1, post, 0, post.size() - 1);
    }

    TreeNode *helper(vector<int> &pre, int preL, int preR, vector<int> &post, int postL, int postR) {
        if (preL > preR || postL > postR) return nullptr;
        TreeNode *cur = new TreeNode(pre[preL]);
        if (preL == preR) return cur;
        int idx = -1;
        for (idx = postL; idx <= postR; ++idx) {
            if (pre[preL + 1] == post[idx]) break;
        }
        cur->left = helper(pre, preL + 1, preL + idx - postL + 1, post, postL, idx);
        cur->right = helper(pre, preL + idx - postL + 2,preR, post, idx + 1, postR);
        return cur;
    }
};