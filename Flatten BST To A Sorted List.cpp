// Approach-1 O(N) O(N)
void inorder(TreeNode<int>* root, vector<int>& ans){
    if(root==NULL)
        return;
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int> ans;
    inorder(root, ans);
    TreeNode<int>* newroot=new TreeNode<int>(ans[0]);
    TreeNode<int>* curr=newroot;
    for(int i=1;i<ans.size();i++){
        curr->right=new TreeNode<int>(ans[i]);
        curr=curr->right;
    }
    return newroot;
}

// Approach 2 O(N) O(H)
void inorder(TreeNode<int>* root, TreeNode<int>*& prev){
    if(root==NULL)
        return;
    inorder(root->left, prev);
    prev->right=new TreeNode<int>(root->data);
    prev=prev->right;
    inorder(root->right, prev);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    TreeNode<int>* dummy=new TreeNode<int>(-1);
    TreeNode<int>* prev=dummy;
    inorder(root, prev);
    return dummy->right;
}

// Alternate of Approach 2 O(N) O(H)
void inorder(TreeNode<int>* root, TreeNode<int>*& prev){
    if(root==NULL)
        return;
    inorder(root->left, prev);
    prev->right=root;
    prev->left=NULL;
    prev=prev->right;
    inorder(root->right, prev);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    TreeNode<int>* dummy=new TreeNode<int>(-1);
    TreeNode<int>* prev=dummy;
    inorder(root, prev);
    prev->left=NULL;
    prev->right=NULL;
    return dummy->right;
}
