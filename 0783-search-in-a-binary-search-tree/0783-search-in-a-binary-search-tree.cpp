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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL)
            return NULL;
        if(root->val == val)   
            return root;
        
        TreeNode* ans;

        if(val < root->val){
            ans=searchBST(root->left, val);
            if(ans)
                return ans;
        }

        else{
            ans=searchBST(root->right, val);
            if(ans)
                return ans;
        }
        return NULL;
    }
};