/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left){
                q.push(temp->left);
                parent[temp->left]=temp;
            }
            if(temp->right){
                q.push(temp->right);
                parent[temp->right]=temp;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;

        if(root==NULL)
            return ans;

        unordered_map<TreeNode*, TreeNode*> parent;
        markParent(root, parent);

        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target]=true;

        int dist=0;

        while(!q.empty()){
            if(dist == k)
                break;
            
            int size=q.size();
            dist++;

            for(int i=0;i<size;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left && !vis[temp->left]){
                    q.push(temp->left);
                    vis[temp->left]=true;
                }
                if(temp->right && !vis[temp->right]){
                    q.push(temp->right);
                    vis[temp->right]=true;
                }
                if(parent[temp] && !vis[parent[temp]]){
                    q.push(parent[temp]);
                    vis[parent[temp]]=true;
                }
            }
            
        }

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};