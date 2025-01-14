class Solution {
public:
    int totalNQueens(int n) {
        return backtrack(0, 0, 0, 0, n);
    }
private:
    int backtrack(int row, int cols, int hills, int dales, int n) {
        if (row == n) return 1;
        int count = 0;
        int free_columns = ((1 << n) - 1) & (~(cols | hills | dales));
        while (free_columns) {
            int curr_column = free_columns & (-free_columns);
            free_columns ^= curr_column;
            count += backtrack(row + 1, cols | curr_column, (hills | curr_column) << 1, (dales | curr_column) >> 1, n);
        }
        return count;
    }
};