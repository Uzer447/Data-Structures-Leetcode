
class Solution {
public:
  void greatarBST(TreeNode*& root, int& key) {
    if(!root) return;

      greatarBST(root->right, key);
      key += root->val;
      root->val=key;

      greatarBST(root->left, key);

    return;         
 }

   TreeNode* convertBST(TreeNode* root) {
     int key=0;  
     greatarBST(root, key);

   return root; 
 }
};