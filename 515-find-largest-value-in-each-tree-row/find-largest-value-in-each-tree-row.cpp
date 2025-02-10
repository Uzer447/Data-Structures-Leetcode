class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;

        dfs(root, 0, res);

        return res;
    }

    void dfs(TreeNode* node, int level, std::vector<int>& res) {
        if (!node) {
            return;
        }

        if (level == res.size()) {
            res.push_back(node->val);
        } else {
            res[level] = std::max(res[level], node->val);
        }

        dfs(node->left, level + 1, res);
        dfs(node->right, level + 1, res);
    }    
};