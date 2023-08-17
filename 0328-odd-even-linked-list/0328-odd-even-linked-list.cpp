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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next == NULL)
            return head;
        
        ListNode* oddhead=new ListNode(-1);
        ListNode* oddtail=oddhead;
        
        ListNode* evenhead=new ListNode(-1);
        ListNode* eventail=evenhead;
        bool oddflag=true;
        
        ListNode* curr=head;
        while(curr){
            if(oddflag){
                oddtail->next=curr;
                oddtail=curr;
            }
            else{
                eventail->next=curr;
                eventail=curr;
            }
            oddflag=!oddflag;
            curr=curr->next;
        }
        if(oddhead->next ==NULL)
            return evenhead->next;
        oddtail->next=evenhead->next;
        eventail->next=NULL;
        head=oddhead->next;
        return head;
    }
};