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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        
        int cnt=0;
        ListNode* curr=head;
        ListNode* prev=dummy;
        
        while(curr!=NULL){
            curr=curr->next;
            cnt++;
        }
        
        while(cnt >= k){
            curr=prev->next;
            ListNode* next=curr->next;
            
            for(int i=1;i<k;i++){
                curr->next=next->next;
                next->next=prev->next;
                prev->next=next;
                next=curr->next;
            }
            
            prev=curr;
            cnt-=k;
        }
        return dummy->next;
    }
};