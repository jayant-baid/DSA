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
    int solve(TreeNode* root, int& i, int k){
        if(root==NULL)
            return -1;
        int leftans=solve(root->left, i, k);
        if(leftans!=-1)
            return leftans;
        i++;    
        if(i == k)
            return root->val;

        int rightans=solve(root->right, i, k);
        if(rightans!=-1)
            return rightans;

        return -1;
    }
    int kthSmallest(TreeNode* root, int k) {
        int i=0;
        return solve(root, i, k);
    }
};