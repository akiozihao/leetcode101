//
// Created by akio on 2021/1/25.
//
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        unordered_map<int, int> m;
        for (int i = 0; i < inorder.size(); ++i) {
            m[inorder[i]] = i;
        }
        return helper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, m);
    }

private:
    TreeNode *
    helper(vector<int> &inorder, int iL, int iR, vector<int> &postorder, int pL, int pR, unordered_map<int, int> &m) {
        if (iL > iR || pL > pR) return nullptr;
        TreeNode *cur = new TreeNode(postorder[pR]);
        int idx = m[cur->val];
        cur->left = helper(inorder,iL,idx-1,postorder,pL,pL+idx-1-iL,m);
        cur->right = helper(inorder,idx+1,iR,postorder,pL+idx-iL,pR-1,m);
        return cur;
    }
};