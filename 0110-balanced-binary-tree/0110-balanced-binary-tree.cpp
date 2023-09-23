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
    int height(TreeNode* root){
        if(root==NULL)
            return 0;

        int left=height(root->left);
        int right=height(root->right);

        return 1+max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;

        int leftheight = height(root->left);
        int rightheight = height(root->right);
        if(abs(leftheight - rightheight) > 1)
            return false;

        bool left=isBalanced(root->left);
        if(!left)
            return false;
        
        bool right=isBalanced(root->right);
        if(!right)
            return false;

        return true;

    }
};