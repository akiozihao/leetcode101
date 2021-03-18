#include <stack>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* p = dummy;
        ListNode *start, *end;
        for (int i = 0; i <= right; ++i) {
            if (i == left - 1) {
                start = p;
            }
            p = p->next;
        }
        end = p;
        start->next = reversePart(start->next,end);
        return dummy->next;
    }
    private:
    ListNode * reversePart(ListNode *head, ListNode *tail){
        if(head==tail || head->next == tail){
            return head;
        }
        ListNode *p,*q;
        q = tail;
        while(head!=tail){
            p = head->next;
            head->next = q;
            q = head;
            head = p;
        }
        return q;
    }
};