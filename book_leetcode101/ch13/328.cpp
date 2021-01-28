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
    ListNode *oddEvenList(ListNode *head) {
        if (!head) return head;
        ListNode *odd = head, *evenHead = head->next, *even = head->next;
        while (odd && even) {
            odd->next = even->next;
            odd = even->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};