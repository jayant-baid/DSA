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
    TreeNode* constructBST(vector<int>& preorder, int& i,int minval, int maxval){
        if(i >= preorder.size() || preorder[i] > maxval || preorder[i] < minval)
            return NULL;
        
        TreeNode* root=new TreeNode(preorder[i++]);
        root->left=constructBST(preorder, i, minval, root->val);
        root->right=constructBST(preorder, i, root->val, maxval);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return constructBST(preorder, i, INT_MIN, INT_MAX);
    }
};