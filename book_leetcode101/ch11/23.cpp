//
// Created by akio on 2021/1/13.
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        auto cmp = [](ListNode *&a, ListNode *&b) {
            return a->val < b->val;
        };
        ListNode *dummy = new ListNode(-1);
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> q(cmp);
        for (auto node:lists) {
            if (node) q.push(node);
        }
        ListNode *cur = dummy;
        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            cur->next = t;
            cur = cur->next;
            if (cur->next) {
                q.push(cur->next);
            }
        }
        return dummy->next;
    }
};