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
    
    void check(TreeNode* root, vector<int>& arr, int& index){
        if(root==NULL)
            return;
        check(root->left, arr, index);

        cout<<root->val << " "<<arr[index]<<endl;

        if(root->val != arr[index])
            root->val = arr[index];
        index++;

        check(root->right, arr, index);
    }
    void inorder(TreeNode* root, vector<int>& ans){
        if(root==NULL)
            return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    void recoverTree(TreeNode* root) {
        vector<int> arr;
        int index=0;
        inorder(root, arr);
        sort(arr.begin(), arr.end());
        check(root, arr, index);
    }
};