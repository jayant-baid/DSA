/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return head;
        Node* temp=head;
        while(temp!=NULL){
            
            Node* newNode= new Node(temp->val);
            Node* next=temp->next;
            temp->next=newNode;
            newNode->next=next;
            temp=next;
        }
    
        temp=head;

        while(temp && temp->next){
            
            if(temp->random)
                temp->next->random=temp->random->next;

            temp=temp->next->next;
        }
        
        temp=head;
        Node* clone=temp->next;
        Node* ans=temp->next;
        
        while(temp && clone){
            temp->next=clone->next;
            temp=temp->next;
            
            if(temp)
                clone->next=temp->next;
            clone=clone->next;
        }
        return ans;
    }
};