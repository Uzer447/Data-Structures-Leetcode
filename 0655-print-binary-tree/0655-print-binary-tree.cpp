class Solution {
private:
    int getDepth(TreeNode* node) {
        if (node->left == NULL && node->right == NULL)
            return 1;
        else if (node->left == NULL)
            return getDepth(node->right) + 1;
        else if (node->right == NULL)
            return getDepth(node->left) + 1;
        else
            return max(getDepth(node->left), getDepth(node->right)) + 1;
    }

    void addNodeToResult(TreeNode* node, vector<vector<string>>& result,
                         int row, int bottom, int top) {
        int middle = (top - bottom) / 2 + bottom;
        result[row][middle] = to_string(node->val);
        if (node->left != NULL)
            addNodeToResult(node->left, result, row + 1, bottom, middle - 1);
        if (node->right != NULL)
            addNodeToResult(node->right, result, row + 1, middle + 1, top);
    }

public:
    vector<vector<string>> printTree(TreeNode* root) {
        int depth = getDepth(root);
        int cols = pow(2, depth) - 1;
        vector<vector<string>> result(depth, vector<string>(cols, ""));
        addNodeToResult(root, result, 0, 0, cols - 1);
        return result;
    }
};