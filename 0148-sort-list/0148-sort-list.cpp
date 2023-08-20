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
    ListNode* getMiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* left, ListNode* right){
        if(left==NULL)
            return right;
        if(right==NULL)
            return left;
        
        ListNode* ans=new ListNode(-1);
        ListNode* temp=ans;
        while(left && right){
            if(left->val < right->val){
                ans->next=left;
                ans=left;
                left=left->next;
            }
            else{
                ans->next=right;
                ans=right;
                right=right->next;
            }
        }
        if(left)
            ans->next=left;
        if(right)
            ans->next=right;
        
        return temp->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next==NULL)
            return head;
        
        ListNode* mid=getMiddle(head);
        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next=NULL;
        
        left=sortList(left);
        right=sortList(right);
        return merge(left, right);
    }
};