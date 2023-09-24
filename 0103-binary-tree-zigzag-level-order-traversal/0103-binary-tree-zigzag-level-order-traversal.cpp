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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root==NULL)
            return ans;
        q.push(root);
    
        bool left2right=true;

        while(!q.empty()){
            int size=q.size();
            vector<int> row(size);

            for(int i=0;i<size;i++){
                auto temp=q.front();
                q.pop();
                int index= left2right ? i : size-1-i;
                row[index]=temp->val;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            left2right=!left2right;
            ans.push_back(row);

        }
        return ans;
    }
};