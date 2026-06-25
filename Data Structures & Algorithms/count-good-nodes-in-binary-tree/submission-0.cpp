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
    int maxi=0;
    int dfs(TreeNode *temp,int maxi)
    {
        if(temp==NULL)
        {
            return 0;
        }
        int res=0;
        if(maxi <= temp->val)
        {
            res=1;
        }
        maxi=max(maxi,temp->val);
        res+=dfs(temp->right,maxi);
        res+=dfs(temp->left,maxi);
        return res;
    }
    int goodNodes(TreeNode* root) 
    {
        return dfs(root,root->val);
    }
};
