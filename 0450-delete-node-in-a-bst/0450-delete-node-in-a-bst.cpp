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
    TreeNode* findlastrightchild(TreeNode* root){
        if(root->right == NULL)
            return root;

        return findlastrightchild(root->right);
    }
    TreeNode* delnode(TreeNode* root){
        if(root->left == NULL)
            return root->right;
        if(root->right == NULL)
            return root->left;

        TreeNode* rightchild=root->right;
        TreeNode* lastrightchild=findlastrightchild(root->left);
        lastrightchild->right=rightchild;

        return root->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
            return NULL;
        if(root->val == key)
            return delnode(root);

        TreeNode* curr=root;
        while(curr){
            if(curr->val > key){
                if(curr->left && curr->left->val == key){
                    curr->left=delnode(curr->left);
                    break;
                }
                else
                    curr=curr->left;
            }
            else{
                if(curr->right && curr->right->val == key){
                    curr->right=delnode(curr->right);
                    break;
                }
                else
                    curr=curr->right;
            }
        }

        return root;
    }
};