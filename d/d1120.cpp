//
// Created by akio on 2020/11/20.
//


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (head == nullptr) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *p = head, *q = head->next;
        while (q != nullptr) {
            if (p->val <= q->val)
                p = p->next;
            else {
                ListNode *prev = dummy;
                while (prev->next->val <= q->val)
                    prev = prev->next;
                p->next = q->next;
                q->next = prev->next;
                prev->next = q;
            }
            q = p->next;
        }
        return dummy->next;
    }
};