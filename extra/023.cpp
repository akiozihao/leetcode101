//
// Created by akio on 2020/12/23.
//
#include <vector>
#include <queue>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    class Stats{
    public:
        int val;
        ListNode *ptr;
        bool operator < (const Stats &rhs) const {
            return val > rhs.val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<Stats> pq;
        for(const auto &list:lists){
            if(list){
                pq.push({list->val,list});
            }
        }
        ListNode dummy;
        ListNode *p = &dummy;
        while(!pq.empty()){
            Stats t = pq.top();
            pq.pop();
            p->next = t.ptr;
            if(t.ptr->next){
                pq.push({t.ptr->next->val,t.ptr->next});
            }
            p = p->next;
        }
        return dummy.next;
    }
};