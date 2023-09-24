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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> nodes; 
        queue<pair<TreeNode*, pair<int, int>>> q;

        if(root==NULL)
            return ans;

        q.push({root, {0, 0}});
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            TreeNode* node=temp.first;
            int vertix=temp.second.first;
            int level=temp.second.second;

            nodes[vertix][level].insert(node->val);
            if(node->left)
                q.push({node->left, {vertix-1, level+1}});
            if(node->right)
                q.push({node->right, {vertix+1, level+1}});
        }

        for(auto i : nodes){
            vector<int> tempans;
            for(auto j : i.second){
                for(auto k : j.second)
                    tempans.push_back(k);
            }
            ans.push_back(tempans);
        }
        return ans;
    }
};