class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> queens(n);
        function<void(int, int, int, int)> dfs = [&](int row, int cols, int diag1, int diag2) {
            if (row == n) {
                vector<string> board(n, string(n, '.'));
                for (int i = 0; i < n; ++i) board[i][queens[i]] = 'Q';
                res.push_back(board);
                return;
            }
            int bits = ((1 << n) - 1) & (~(cols | diag1 | diag2));
            while (bits) {
                int pick = bits & -bits;
                bits &= bits - 1;
                int col = __builtin_ctz(pick);
                queens[row] = col;
                dfs(row + 1, cols | pick, (diag1 | pick) << 1, (diag2 | pick) >> 1);
            }
        };
        dfs(0, 0, 0, 0);
        return res;
    }
};