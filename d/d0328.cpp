#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class BSTIterator {
   public:
    BSTIterator(TreeNode *root) {
        p = root;
    }

    int next() {
        while(p){
            stk.push(p);
            p = p->left;
        }
        p = stk.top();
        stk.pop();
        int val = p->val;
        p = p->right;
        return val;
    }

    bool hasNext() {
        return p || !stk.empty();
    }

   private:
    TreeNode *p;
    stack<TreeNode*> stk;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */