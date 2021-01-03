//
// Created by akio on 2021/1/3.
//



struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (!head) return head;
        ListNode *small = new ListNode(-1);
        ListNode *large = new ListNode(-1);
        ListNode *p = head, *p1 = small, *p2 = large;
        while (p) {
            if (p->val < x) {
                p1->next = p;
                p1 = p1->next;
            } else {
                p2->next = p;
                p2 = p2->next;
            }
            p = p->next;
        }
        p1->next = large->next;
        return small->next;
    }
};