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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp = slow->next;
        slow->next = NULL;
        ListNode* temp2 = NULL;
        while (temp) {
            ListNode* x = temp->next;
            temp->next = temp2;
            temp2 = temp;
            temp = x;
        }
        ListNode* l1 = head;
        ListNode* l2 = temp2;
        while (l2) {
            temp = l1->next;
            temp2 = l2->next;
            l1->next = l2;
            l2->next = temp;
            l1 = temp;
            l2 = temp2;
        }
    }
};
