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
void postorder(TreeNode* root,vector<int> &ans)
    {
        if(root==NULL)
        return;
        postorder(root->left,ans);
        postorder(root->right,ans);
        ans.push_back(root->val);
    }
void iterpostorder(TreeNode* root,vector<int> &ans)
{
    if(root==NULL)
    return;
    stack<TreeNode*> st1,st2;
    st1.push(root);
    while(!st1.empty())
    {
        auto node=st1.top();
        st1.pop();
        st2.push(node);
        if(node->left!=NULL)
        {
            st1.push(node->left);
        }
        if(node->right!=NULL)
        {
            st1.push(node->right);
        }
    }
    while(!st2.empty())
    {
        ans.push_back(st2.top()->val);
        st2.pop(); 
    }
}
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        iterpostorder(root,ans);
        return ans;
    }
};