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
    int height(TreeNode* root)
    {
        if(root==NULL) return 0;
        int lefth=height(root->left);
        int righth=height(root->right);
        return max(lefth,righth)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        if(abs(height(root->left)-height(root->right))<=1 && isBalanced(root->left) && isBalanced(root->right)) return true;
        return false;
    }
};