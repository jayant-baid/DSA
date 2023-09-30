    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr=root;
        while(curr!=NULL){
            // Case 1
            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr=curr->right;
            }
            // Case 2
            else{
                TreeNode* prev=curr->left;
                while(prev->right != NULL && prev->right != curr)
                    prev=prev->right;

                if(prev->right == NULL){
                    prev->right=curr;
                    ans.push_back(curr->val);
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                    curr=curr->right;
                }
            }
        }        
        return ans;
    }
