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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *head = NULL, *curr=NULL;
        while (l1 && l2) {
            ListNode *temp = new ListNode((l1->val + l2->val + carry) % 10);
            carry = (l1->val + l2->val + carry) / 10;
            if (!head) {
                head = temp;
                curr = head;
            } else {
                curr->next = temp;
                curr = curr->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            curr->next = new ListNode((l1->val + carry) % 10);
            curr = curr->next;
            carry = (l1->val + carry) / 10;
            l1 = l1->next;
        }
        while (l2) {
            curr->next = new ListNode((l2->val + carry) % 10);
            curr = curr->next;
            carry = (l2->val + carry) / 10;
            l2 = l2->next;
        }
        if (carry) {
            curr->next = new ListNode(carry);
        }
        return head;
    }
};
