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
    TreeNode* build(vector<int> &inorder,int start,int end)
    {
        if(start>end) return NULL;
        int mid=(start+end)>>1;
        TreeNode* root=new TreeNode(inorder[mid]);
        root->left=build(inorder,start,mid-1);
        root->right=build(inorder,mid+1,end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int st=0;
        int end=nums.size()-1;
        return build(nums,st,end);
    }
};