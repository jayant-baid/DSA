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
    ListNode* reverse(ListNode* head, int k, int length){
        if(length<k)
            return head;
        if(head ==NULL)
            return NULL;
        
        ListNode* curr=head;
        ListNode* prev=NULL;
        int cnt=0;
        
        while(curr!=NULL && cnt<k){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            cnt++;
        }
        if(curr!=NULL)
            head->next=reverse(curr, k, length-k);
        
        return prev;
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt=0;
        ListNode* curr=head;
        while(curr){
            curr=curr->next;
            cnt++;
        }
        return reverse(head, k, cnt);
    }
};