class Solution {
public:
    pair<TreeNode*, int> dfs(TreeNode* node) {
        if(!node) return {nullptr, 0};
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        if(left.second == right.second) return {node, left.second + 1};
        return left.second > right.second ? make_pair(left.first, left.second + 1) : make_pair(right.first, right.second + 1);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;
    }
};