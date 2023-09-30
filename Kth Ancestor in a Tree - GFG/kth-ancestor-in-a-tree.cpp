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
bool solve(Node* root, int node, int& k, int& ans){
    if(root == NULL)
        return false;
       
    if(root->data == node){
        k--;
        return true;
    }
        
    bool left = solve(root->left, node, k, ans);
    if(left){
        if(k==0){
            ans=root->data;
            return false;
        }
        k--;
        return true;
    }
    bool right = solve(root->right, node, k, ans);
    if(right){
        if(k==0){
            ans=root->data;
            return false;
        }
        k--;
        return true;
    }
    // return false;
}
int kthAncestor(Node *root, int k, int node)
{
    int ans=-1;
    solve(root, node, k, ans);
 
    return ans;
}
