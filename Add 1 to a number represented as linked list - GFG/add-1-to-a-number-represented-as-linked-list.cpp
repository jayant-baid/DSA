//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverse(Node* head){
        Node* curr=head;
        Node* prev=NULL;
        
        while(curr){
            Node* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    Node* addFunc(Node* head){
        Node* dummy=new Node(-1);
        Node* temp=dummy;
        
        int carry=1;
        while(head || carry){
            int sum=0;
            if(head){
                sum+=head->data;
                head=head->next;
            }
            
            sum+=carry;
            carry=sum/10;
            
            Node* node=new Node(sum%10);
            temp->next=node;
            temp=node;
        }
        return dummy->next;
    }
    Node* addOne(Node *head) 
    {
        head=reverse(head);
        
        Node* ans=addFunc(head);
        
        ans=reverse(ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends