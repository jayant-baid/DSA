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
    ListNode* reverse(ListNode* head){
        ListNode* curr=head, *prev=NULL;
        
        while(curr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
    ListNode* addFunc(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        
        int carry=0;
        while(l1 || l2 || carry){
            int sum=0;
            if(l1){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            
            int digit=sum%10;
            carry=sum/10;
            ListNode* node=new  ListNode(digit);
            temp->next=node;
            temp=node;
        }
        return dummy->next;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverse(l1);
        l2=reverse(l2);
        
        ListNode* ans=addFunc(l1, l2);
            
        ans=reverse(ans);
        return ans;
    }
};