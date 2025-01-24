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
    void preordere(TreeNode* root,vector<int> &ans)
    {
        if(root==NULL)
        return;
        ans.push_back(root->val);
        preordere(root->left,ans);
        preordere(root->right,ans);
    }
    void iterpreorder(TreeNode* root,vector<int> &ans)
    {
        stack<TreeNode*> st;
        if(root==NULL)return;
        st.push(root);
        while(!st.empty())
        {
            auto node=st.top();
            st.pop();
            ans.push_back(node->val);
            if(node->right!=NULL)st.push(node->right);
            if(node->left!=NULL)st.push(node->left);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        iterpreorder(root,ans);
        return ans;
    }
};