/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return NULL;
        }
        for (int i=1; i<lists.size(); ++i) {
            lists[i] = merge(lists[i], lists[i-1]);
        }
        return lists.back();
    }

    ListNode* merge(ListNode *l1, ListNode *l2) {
        ListNode *head = NULL;
        ListNode *cur = NULL;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                if (head == NULL) {
                    head = l1;
                    cur = head;
                    l1 = l1->next;
                } else {
                    cur->next = l1;
                    l1 = l1->next;
                    cur = cur->next;
                }
            } else {
                if (head == NULL) {
                    head = l2;
                    cur = head;
                    l2 = l2->next;
                } else {
                    cur->next = l2;
                    l2 = l2->next;
                    cur = cur->next;
                }
            }
        }
        if (l1) {
            cur->next = l1;
        }
        if (l2) {
            cur->next = l2;
        }
        return head;
    }
};
