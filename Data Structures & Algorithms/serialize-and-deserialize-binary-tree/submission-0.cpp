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

class Codec {
public:

    // Encodes a tree to a single string.
    void helper(TreeNode *root,string &res)
    {
        if(root==NULL)
        {
            res+="N,";
            return ;
        }
        res+=to_string(root->val)+",";
        helper(root->left,res);
        helper(root->right,res);


    }
    string serialize(TreeNode* root) 
    {
        string res;
        helper(root,res);
        return res;
        
    }

    // Decodes your encoded data to tree.
    TreeNode *helper2(vector<string> &list,int &index)
    {
        if(list[index]=="N")
        {
            index++;
            return NULL;
        }
        TreeNode *root=new TreeNode(stoi(list[index]));
        index++;
        root->left=helper2(list,index);
        root->right=helper2(list,index);
        return root;

    }
    TreeNode* deserialize(string data) 
    {
        vector<string> list;
        stringstream ss(data);
        string temp;
        while(getline(ss,temp,','))
        {
            list.push_back(temp);
        }
        int index=0;
        return helper2(list,index);

        
    }
};
