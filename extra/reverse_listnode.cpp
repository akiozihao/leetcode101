
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
   public:
    // 双指针 迭代
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = curr->next;
        }
        return prev;
    }
    // 递归
    ListNode* reverseList(ListNode* head) {
        if (head->next == nullptr) return head;
        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
    // 翻转前n个节点 （节点坐标从1开始, n <= 链表长度）
    ListNode* successor = nullptr;  // 后驱节点
    ListNode* reverseN(ListNode *head, int n) {
        if(n==1){
            successor = head->next;
            return head;
        }
        ListNode *last = reverseN(head->next,n-1);
        head->next->next = head;
        head->next = successor;
        return last;
    }

    ListNode* reverseBetween(ListNode *head,int m,int n){
        if(m==1){
            return reverseN(head,n);
        }
        head-> next = reverseBetween(head->next,m-1,n-1);
        return head;
    }
};