/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
*/
// Create BT where an array of 7 length is given
Node* createTree(vector<int>&arr){
    Node* root = new Node(arr[0]);
    root->left = new Node(arr[1]);
    root->right = new Node(arr[2]);
    root->left->left = new Node(arr[3]);
    root->left->right = new Node(arr[4]);
    root->right->left = new Node(arr[5]);
    root->right->right = new Node(arr[6]);
    return root;
}
