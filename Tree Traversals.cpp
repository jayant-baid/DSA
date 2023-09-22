/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

// https://www.codingninjas.com/studio/problems/tree-traversal_981269

void solve(TreeNode *root, vector<int>& pre, vector<int>& inn, vector<int>& post){
    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});

    while(!st.empty()){
        auto itr=st.top();
        st.pop();

        if(itr.second == 1){
            pre.push_back(itr.first->data);
            itr.second++;
            st.push(itr);
            if(itr.first->left)
                st.push({itr.first->left, 1});
        }
        else if(itr.second == 2){
            inn.push_back(itr.first->data);
            itr.second++;
            st.push(itr);
            if(itr.first->right)
                st.push({itr.first->right, 1});
        }
        else{
            post.push_back(itr.first->data);
        }
    }
    
}
vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<vector<int>> ans;
    vector<int>pre, inn, post;
    
    if(root == NULL)
        return ans;
        
    solve(root, pre, inn, post);
    ans.push_back(inn);
    ans.push_back(pre);
    ans.push_back(post);
    return ans;
}
