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
class FindElements {
public:
    set<int> st;
    void bfs(TreeNode* root)
    {
        if(root==NULL) return;
        queue<TreeNode*> q;
        q.push(root);
        root->val=0;
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            st.insert(node->val);
            if(node->left)
            {
                node->left->val=node->val*2+1;
                q.push(node->left);
            }
            if(node->right)
            {
                node->right->val=node->val*2+2;
                q.push(node->right);
            }
        }
    }
    FindElements(TreeNode* root) {
        bfs(root);
    }
    
    bool find(int target) {
        return st.count(target)==1;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */