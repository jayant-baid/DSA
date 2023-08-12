#include <bits/stdc++.h> 
/************************************************************

    Following is the linkedList class structure:

    class Node {
    public:
        int data;
        Node *next;

        Node(int val) {
            this->data = val;
            next = NULL;
        }
        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
};

************************************************************/
void insertatHead(Node * ( & head), int val){
    Node* temp=new Node(val);
    temp->next=head;
    head=temp;
    return;
}
void insertatTail(Node * ( & tail), int val){
    Node* temp=new Node(val);
    tail->next=temp;
    tail=temp;
    return;
} 
void insert(Node * ( & head), int n, int pos, int val) {
    if(pos == 0){
        insertatHead(head, val);
        return;
    }
    int cnt=1;
    Node* temp =head;
    while(cnt < pos){
        temp=temp->next;
        cnt++;
    }
    // if(temp->next == NULL){
    //     insertatTail(temp, val);
    //     return;
    // }
    Node* nodeToInsert=new Node(val);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;
    return;

}
