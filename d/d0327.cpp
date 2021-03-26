
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
   public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || !head || !head->next) return head;
        int n = 1;
        ListNode* tail = head;
        while (tail->next != nullptr) {
            ++n;
            tail = tail->next;
        }
        // 成环
        tail->next = head;
        k = k % n;
        for (int i = 0; i < n - k; ++i) {
            tail = tail->next;
        }
        head = tail->next;
        tail->next = nullptr;
        return head;
    }
};