//
// Created by akio on 2021/1/21.
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
    ListNode *swapPairs(ListNode *head) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy, *cur = head;
        while (cur && cur->next) {
            ListNode *next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
            pre = cur;
            cur = pre->next;
        }
        return dummy->next;
    }
};