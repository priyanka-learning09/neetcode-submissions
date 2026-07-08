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
    int dfs(TreeNode *root,int &maxsum)
    {
        if(root==NULL)
        {
            return 0;
        }
        int lh=dfs(root->left,maxsum);
        int rh=dfs(root->right,maxsum);
        if(lh<0)
        {
            lh=0;
        }
        if(rh<0)
        {
            rh=0;
        }
        maxsum=max(maxsum,lh+rh+root->val);
        return root->val+max(lh,rh);

    }
    int maxPathSum(TreeNode* root) 
    {
        if(root==NULL)
        {
            return 0;
        }
        int maxsum=INT_MIN;
        dfs(root,maxsum);
        return maxsum;
            
    }
};
