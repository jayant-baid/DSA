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
        if(root == NULL)
            return 0;

        int left=height(root->left);
        int right=height(root->right);

        return 1+max(left, right);
    }
    void solve(TreeNode* root, int& maxi){
        if(root == NULL)
            return;

        int leftheight=height(root->left);
        int rightheight=height(root->right);
        maxi=max(maxi, leftheight + rightheight);
        solve(root->left, maxi);
        solve(root->right, maxi);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return -1;

        int maxi=0;
        solve(root, maxi);
        return maxi;
    }
};