//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function


//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function
int kthAncestor(Node *root, int k, int node)
{
    unordered_map<int, int> parent;
    parent[root->data]=-1;
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        
        if(temp->left){
            q.push(temp->left);
            parent[temp->left->data]=temp->data;
        }
        if(temp->right){
            q.push(temp->right);
            parent[temp->right->data]=temp->data;
        }
    }
    
    while(k && parent[node]!=-1){
        node=parent[node];
        k--;
        if(k==0)
            return node;
    }
    return -1;
}
