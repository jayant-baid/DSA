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
        Node* dummy=new Node(-1);
        Node* clonetail=dummy;
        
        Node* original=head;
        while(original){
            Node* tempnode=new Node(original->val);
            clonetail->next=tempnode;
            clonetail=tempnode;
            
            original=original->next;
        }
        
        unordered_map<Node*, Node*> mpp;
        original=head;
        Node* clone=dummy->next;
        while(original){
            mpp[original]=clone;
            original=original->next;
            clone=clone->next;
        }
    
        original=head;
        clone=dummy->next;
        while(original){
            clone->random=mpp[original->random];
            original=original->next;
            clone=clone->next;
        }
        return dummy->next;
    
    }
};