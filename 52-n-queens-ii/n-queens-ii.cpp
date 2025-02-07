class Solution {
public:
    int total;
    void solve(int n, int row, int cols, int diag1, int diag2) {
        if (row == n) {
            total++;
            return;
        }
        int available = ((1 << n) - 1) & (~(cols | diag1 | diag2));
        while (available) {
            int pos = available & (-available);
            available &= available - 1;
            solve(n, row + 1, cols | pos, (diag1 | pos) << 1, (diag2 | pos) >> 1);
        }
    }
    int totalNQueens(int n) {
        total = 0;
        solve(n, 0, 0, 0, 0);
        return total;
    }
};