class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node* prev=NULL;
    Node* head=NULL;
    
    Node * bToDLL(Node *root)
    {
        if(root==NULL)
            return NULL;
        
        bToDLL(root->left);
        
        if(prev == NULL)
            head=root;
        else{
            prev->right=root;
            root->left=prev;
        }
        prev=root;
        
        bToDLL(root->right);
        
        return head;
    }
};
