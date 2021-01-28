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
    ListNode *reverseList(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr) {
            ListNode *t = curr->next;
            curr->next = prev;
            prev = curr;
            curr = t;
        }
        return prev;
    }

    ListNode *reverseList2(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *newHead = reverseList2(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }

    ListNode *reverseList3(ListNode *head, ListNode *prev = nullptr) {
        if (!head)
            return prev;
        ListNode *next = head->next;
        head->next = prev;
        return reverseList3(next, head);
    }
};