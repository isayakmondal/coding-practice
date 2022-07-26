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
    bool hasCycle(ListNode *head) {
        
        bool ans = false;
        unordered_set<ListNode *> u;
        
        ListNode *temp=head;
        
        while(temp!=NULL){
            
            u.insert(temp);
            temp=temp->next;
            
            if(u.find(temp)!=u.end()){
                ans = true;
                break;
            }
            
        }
        
        return ans;
    }
};