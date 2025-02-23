class Solution {
public:
    vector<int> x2pre, x2post; 
    TreeNode* f(vector<int>& preorder, vector<int>& postorder, int preS, int postS, int postE) {
        if (postS>postE) return NULL;  
        TreeNode* root=new TreeNode(preorder[preS]);
        if (postS==postE) return root;  
        
        int lRoot=preorder[preS+1];  
        int lrPostIdx=x2post[lRoot];  
        root->left=f(preorder, postorder, preS+1, postS, lrPostIdx);
        root->right=f(preorder, postorder, x2pre[postorder[postE-1]], lrPostIdx+1, postE-1);

        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        const int n = preorder.size();
        x2pre.assign(n+1, -1);
        x2post.assign(n+1, -1);
        for (int i=0; i<n; i++) {
            x2pre[preorder[i]]=i;  
            x2post[postorder[i]]=i;  
        }
        return f(preorder, postorder, 0, 0, n-1);
    }
};


