//
// Created by akio on 2021/2/17.
//
#include <vector>

using namespace std;

class Solution {
public:
    struct Node {
        int val, smaller;
        Node *left, *right;

        Node(int v, int s) : val(v), smaller(s), left(nullptr), right(nullptr) {}
    };

    int insert(Node *&root, int val) {
        if (!root) {
            root = new Node(val, 0);
            return 0;
        } else if (root->val > val) {
            root->smaller++;
            return insert(root->left, val);
        } else {
            return insert(root->right, val) + root->smaller + (root->val < val ? 1 : 0);
        }
    }

    vector<int> countSmaller(vector<int> &nums) {
        vector<int> res(nums.size());
        Node *root = nullptr;
        for (int i = nums.size() - 1; i >= 0; --i) {
            res[i] = insert(root, nums[i]);
        }
        return res;
    }
};