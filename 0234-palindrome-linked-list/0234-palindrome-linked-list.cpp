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
    bool checkPalin(ListNode* head1, ListNode* head2){
        while(head2){
            if(head1->val != head2->val)
                return false;
            head1=head1->next;
            head2=head2->next;
        }
        return true;
    }
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* getmiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next==NULL)
            return true;
        
        ListNode* middle=getmiddle(head);
        middle->next=reverse(middle->next);
        
        return checkPalin(head, middle->next);
    }
};