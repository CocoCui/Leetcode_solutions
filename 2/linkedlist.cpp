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
        ListNode* ans = NULL;
        int flag = 0;
        ListNode* last = NULL;
        int v1 = (l1 == NULL) ? 0 : l1 -> val;
        int v2 = (l2 == NULL) ? 0 : l2 -> val;
        while(l1 != NULL || l2 != NULL) {
            int val = v1 + v2 + flag;
            //cout<<l1<<" "<<l2<<" "<<val<<endl;
            ListNode* node = new ListNode(val % 10);
            if(val >= 10) flag = 1; 
            else flag = 0;
            if(ans == NULL) ans = node;
            else last -> next = node;
            last = node;
            if(l1 != NULL && l1 -> next != NULL){
                l1 = l1 -> next;
                v1 = l1 -> val;   
            } else {
                v1 = 0;
                l1 = NULL;
            }
            if(l2 != NULL && l2 -> next != NULL){
                l2 = l2 -> next;
                v2 = l2 -> val;
            } else {
                v2 = 0;
                l2 = NULL;
            }
        } 
        if(flag == 1) {
            last -> next = new ListNode(1);
        }
        return ans;
    }
};
