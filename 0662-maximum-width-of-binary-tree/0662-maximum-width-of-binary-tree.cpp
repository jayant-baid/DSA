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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;

        int width=0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()){
            int size=q.size();
            int mini=q.front().second;
            int first, last;
            for(int i=0;i<size;i++){
                TreeNode* temp = q.front().first;
                int currindex = q.front().second - mini;
                q.pop();

                if(i == 0)
                    first=currindex;
                if(i == size-1)
                    last=currindex;

                if(temp->left)
                    q.push({temp->left, (long long)2*currindex+1});
                if(temp->right)
                    q.push({temp->right, (long long)2*currindex+2});
            }
            width=max(width, last-first+1);
        }
        return width;
    }
};