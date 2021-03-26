#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
   public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        helper(res, head);
        return res;
    }

   private:
    void helper(vector<int>& res, ListNode* node) {
        if (!node) {
            return;
        }
        helper(res, node->next);
        res.push_back(node->val);
    }
};