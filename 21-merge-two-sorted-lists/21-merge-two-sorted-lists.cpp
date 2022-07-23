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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        //Iterative approach
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode *newHead, *temp;
        
        if(l1->val<l2->val){
            
            newHead = l1;
            l1=l1->next;
        }
        else{
            newHead = l2;
            l2=l2->next;
            
        }
        
        temp=newHead;
        
        while(l1&&l2){
            
            if(l1->val<l2->val){
                temp->next=l1;
                l1=l1->next;
            }
            else{
                
                temp->next=l2;
                l2=l2->next;
                
            }
            temp=temp->next;
        }
        
        if(l1==NULL) temp->next=l2;
        else if(l2==NULL) temp->next=l1;
        
        return newHead;
    }
};