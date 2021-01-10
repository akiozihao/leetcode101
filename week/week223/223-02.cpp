//
// Created by akio on 2021/1/10.
//


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *swapNodes(ListNode *head, int k) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *slow = dummy;
        ListNode *fast = dummy;
        int cnt = k;
        while (cnt) {
            fast = fast->next;
            --cnt;
        }
        ListNode *p1 = fast;
        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *p2 = slow;
        int t = p1->val;
        p1->val = p2->val;
        p2->val = t;
        return dummy->next;
    }
};