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
void inorder(TreeNode* root,vector<int> &ans)
    {
        if(root==NULL)
        return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
     void iterinorder(TreeNode* root,vector<int> &ans)
    {
        stack<TreeNode*> st;
        if(root==NULL)return;
        while(true)
        {
            if(root!=NULL)
            {
                st.push(root);
                root=root->left;
            }
            else
            { if(st.empty())break;

                auto node=st.top();
            st.pop();
            ans.push_back(node->val);
            root=root->right;
            }
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        return ans;
    }
};