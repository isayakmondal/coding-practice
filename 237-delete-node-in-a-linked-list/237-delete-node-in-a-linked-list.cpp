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
    void deleteNode(ListNode* node) {
       
        ListNode *temp2, *temp1 = node;
        temp2=temp1->next;
        temp1->val=temp2->val;
        temp1->next=temp2->next;
        delete temp2;
        
    }
};