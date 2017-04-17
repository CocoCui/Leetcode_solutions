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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *before = NULL, *remove = head, *cur = head;
        for(int i = 0; i < n; i++) {
            cur = cur -> next;
        }
        while(cur) {
            cur = cur -> next;
            before = remove;
            remove = remove -> next;
        }
        if(before == NULL) {
            return head -> next;
        }
        before -> next = remove -> next;
        return head;
    }
};
