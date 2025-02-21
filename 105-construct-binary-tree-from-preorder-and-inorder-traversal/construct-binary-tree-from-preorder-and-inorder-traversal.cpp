/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* build(vector<int>& preorder, int prestart, int preend,
                    vector<int>& inorder, int instart, int inend,
    map<int, int> &inMap) {
        if(instart>inend || prestart>preend) return NULL;
        TreeNode* root=new TreeNode(preorder[prestart]);
        int inRoot=inMap[root->val];
        int numsleft=inRoot-instart;
        root->left=build(preorder,prestart+1,prestart+numsleft,inorder,instart,inRoot-1,inMap);
        root->right=build(preorder,prestart+numsleft+1,preend,inorder,inRoot+1,inend,inMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inMap;
        for(int i=0;i<inorder.size();i++)
        inMap[inorder[i]]=i;
        return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inMap);
    }
};