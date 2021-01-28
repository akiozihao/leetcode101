//
// Created by akio on 2021/1/22.
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
    bool isPalindrome(ListNode *head) {
        if (!head) return true;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *slow = dummy, *fast = dummy;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        reverse(slow);
        ListNode *p1 = head, *p2 = slow->next;
        while (p1 && p2) {
            if (p1->val != p2->val) return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        bool res = (p1 == p2);
        reverse(slow);
        return res;
    }

private:
    void reverse(ListNode *pre) {
        ListNode *cur = pre->next;
        while (cur && cur->next) {
            ListNode *t = cur->next;
            cur->next = t->next;
            t->next = pre->next;
            pre->next = t;
        }
    }
};