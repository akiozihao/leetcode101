//
// Created by akio on 2021/1/25.
//
#include <vector>
#include <queue>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root) return {};
        vector<double> res;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size(),sz2 = sz;
            double t = 0.0;
            while(sz){
                TreeNode *node = q.front();
                q.pop();
                t += node->val;
                --sz;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.emplace_back(t/sz2);
        }
        return res;
    }
};