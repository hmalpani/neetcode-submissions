/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        queue<Node*> q;
        if (!head) return nullptr;
        q.push(head);
        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();
            if (mp.find(cur) == mp.end()) {
                mp[cur] = new Node(cur->val);
            }
            if (cur->next && mp.find(cur->next) == mp.end()) {
                mp[cur->next] = new Node(cur->next->val);
                q.push(cur->next);
            }
            if (cur->next) {
                mp[cur]->next = mp[cur->next];
            }
            if (cur->random && mp.find(cur->random) == mp.end()) {
                mp[cur->random] = new Node(cur->random->val);
                q.push(cur->random);
            }
            if (cur->random) {
                mp[cur]->random = mp[cur->random];
            }
        }
        return mp[head];
    }
};
