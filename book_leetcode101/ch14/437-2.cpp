//
// Created by akio on 2021/1/23.
//

#include <unordered_map>

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
    int pathSum(TreeNode *root, int sum) {
        unordered_map<int, int> m;
        m[0] = 1;
        return helper(root, sum, 0, m);

    }

private:
    int helper(TreeNode *node, int sum, int curSum, unordered_map<int, int> &m) {
        if (!node) return 0;
        curSum += node->val;
        int res = m[curSum - sum];
        ++m[curSum];
        res += helper(node->left, sum, curSum, m) + helper(node->right, sum, curSum, m);
        --m[curSum];
        return res;
    }
};