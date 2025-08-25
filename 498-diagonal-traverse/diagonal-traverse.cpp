class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int m = mat.size();
        int n = mat[0].size();
bool upward = true;

    int row = 0, col = 0;

    while (row < m && col < n) {
        ans.push_back(mat[row][col]);

        int new_row = row + (upward ? -1 : 1);
        int new_col = col + (upward ? 1 : -1);

        if (new_row < 0 || new_row == m || new_col < 0 || new_col == n) {
            if (upward) {
                row += (col == n - 1) ? 1 : 0;
                col += (col < n - 1) ? 1 : 0;
            } else {
                col += (row == m - 1) ? 1 : 0;
                row += (row < m - 1) ? 1 : 0;
            }
            upward = !upward;
        } else {
            row = new_row;
            col = new_col;
        }
    }

    return ans;
    }
};