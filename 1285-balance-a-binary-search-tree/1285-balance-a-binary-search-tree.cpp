/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans){
        if(root==NULL)
            return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    TreeNode* makeBST(vector<int>& in, int start, int end){
        if(start > end)
            return NULL;
        int mid=start+(end-start)/2;
        TreeNode* newroot=new TreeNode(in[mid]);
        newroot->left=makeBST(in, start, mid-1);
        newroot->right=makeBST(in, mid+1, end);
        return newroot;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return makeBST(ans, 0, ans.size()-1);
    }
};