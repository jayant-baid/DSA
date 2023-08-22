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
    ListNode *getIntersectionNode(ListNode *first, ListNode *second) {
        ListNode* d1=first;
        ListNode* d2=second;
        
        while(d1 && d2){
            if(d1 == d2)
                return d1;
            
            d1=d1->next;
            d2=d2->next;
            if(d1==NULL && d2!=NULL)
                d1=second;
            if(d2==NULL && d1!=NULL)
                d2=first;
        }
        return NULL;
    }
};