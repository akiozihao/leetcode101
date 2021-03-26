#include <bits/stdc++.h>
using namespace std;
class Node {
   public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;
        Node* root = new Node(head->val);

        queue<Node*> q;
        unordered_map<Node*, Node*> visited;
        visited[head] = root;

        q.push(head);
        while (!q.empty()) {
            Node* cur = q.front();

            if (cur->next && visited.find(cur->next) == visited.end()) {
                visited[cur->next] = new Node(cur->next->val);
                q.push(cur->next);
            }
            if (cur->random && visited.find(cur->random) == visited.end()) {
                visited[cur->random] = new Node(cur->random->val);
                q.push(cur->random);
            }
            visited[cur]->next = visited[cur->next];
            visited[cur]->random = visited[cur->random];
            q.pop();
        }
        return root;
    }
};