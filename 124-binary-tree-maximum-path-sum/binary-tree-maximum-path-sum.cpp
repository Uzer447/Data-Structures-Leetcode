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
    int postorder(TreeNode* root,int &ans)
    {
        if(root==NULL)
        return 0;
        int leftsum=max(0,postorder(root->left,ans));
        int rightsum=max(0,postorder(root->right,ans));
        ans=max(ans,leftsum+rightsum+root->val);
        return max(leftsum,rightsum)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        postorder(root,ans);
        return ans;
    }
};