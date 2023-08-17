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
    ListNode * fcd(ListNode *head){
        if(head==NULL || head->next==NULL)
            return NULL;
        
        ListNode *slow=head, *fast=head;
        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            
            if(fast==slow)
                return slow;
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head;
        ListNode *intersection=fcd(head);
        
        if(intersection == NULL)
            return NULL;
        
        while(slow!=NULL){
            if(slow == intersection)
                return slow;
            slow=slow->next;
            intersection=intersection->next;
            
        }
        return NULL;
    }
};