/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head;
        ListNode* odd = head, *even = head -> next, *oc = head, *ec = head -> next;
        int count = 1;
        head = head -> next -> next;
        while(head) {
            if(count % 2) {
                oc -> next = head;
                oc = head;
            } else {
                ec -> next = head;
                ec = head;
            }
            head = head -> next;
            count ++;
        }
        oc -> next = even;
        ec -> next = NULL;
        return odd;
    }
};
