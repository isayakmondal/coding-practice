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
    
    ListNode * reverseList(ListNode *head){
        
        if(head==NULL || head->next==NULL) return head;
        ListNode *p=NULL, *c=head, *n=head->next;
        
        while(c!=NULL ){
            //O(n) time, 
            
            c->next=p;
            p=c;
            c=n;
            if(n!=NULL) n=n->next;

            
        }
        return p;
    }
    
    ListNode * middle(ListNode * head){
        
        if(head==NULL) return head;
        ListNode *slow=head, *fast=head;
        
        while(fast!=NULL && fast->next!=NULL){
            
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    bool isPalindrome(ListNode* head) {
        
        ListNode *mid, *rev=head, *temp2=head;
        
        mid = middle(head);
       
        rev = reverseList(mid);
        
        while(rev!=NULL && temp2!=mid){
            
            if(rev->val!=temp2->val) return false;
            
            rev=rev->next;
            temp2=temp2->next;
        }
        
        return true;
    }
};