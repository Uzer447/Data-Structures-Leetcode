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
int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        if(left==-1 || right==-1)return -1;
        if(abs(left-right)>1)return -1;
        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        if(maxDepth(root)==-1)
        return false;
        return true;
    }
};