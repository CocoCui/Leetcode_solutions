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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1, l2, 0);
    }
private:
    ListNode* add(ListNode* l, ListNode* r, int c) {
        if(l == NULL && r == NULL) {
            if(c == 0) return NULL;
            else return new ListNode(c);
        }
        if(l == NULL) {
            int val = r -> val + c;
            ListNode* cur = new ListNode(val % 10);
            cur -> next = add(NULL, r -> next, val / 10);
            return cur;
        } else if(r == NULL){
            int val = l -> val + c;
            ListNode* cur = new ListNode(val % 10);
            cur -> next = add(NULL, l -> next, val / 10);
            return cur;
        } else {
            int val = l -> val + r -> val + c;
            ListNode* cur = new ListNode(val % 10);
            cur -> next = add(l -> next, r -> next, val / 10);
            return cur;
        }
        
    }
};
