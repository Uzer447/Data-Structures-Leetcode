class Solution {
public:
    int rows[9], cols[9], boxes[9];
    vector<pair<int, int>> emptyCells;
    vector<vector<char>>* board;
    bool solve() {
        if (emptyCells.empty()) return true;
        int minOptions = 10, minCellIndex = -1;
        for (int idx = 0; idx < emptyCells.size(); ++idx) {
            int i = emptyCells[idx].first, j = emptyCells[idx].second;
            int used = rows[i] | cols[j] | boxes[(i / 3) * 3 + j / 3];
            int possible = ~used & 0x1FF;
            int count = __builtin_popcount(possible);
            if (count < minOptions) {
                minOptions = count;
                minCellIndex = idx;
                if (count == 1) break;
            }
        }
        if (minOptions == 0) return false;
        int i = emptyCells[minCellIndex].first, j = emptyCells[minCellIndex].second;
        emptyCells.erase(emptyCells.begin() + minCellIndex);
        int used = rows[i] | cols[j] | boxes[(i / 3) * 3 + j / 3];
        int possible = ~used & 0x1FF;
        while (possible) {
            int digitMask = possible & -possible;
            int digit = __builtin_ctz(digitMask);
            (*board)[i][j] = digit + '1';
            rows[i] |= digitMask;
            cols[j] |= digitMask;
            boxes[(i / 3) * 3 + j / 3] |= digitMask;
            if (solve()) return true;
            rows[i] &= ~digitMask;
            cols[j] &= ~digitMask;
            boxes[(i / 3) * 3 + j / 3] &= ~digitMask;
            possible &= ~digitMask;
        }
        (*board)[i][j] = '.';
        emptyCells.insert(emptyCells.begin() + minCellIndex, make_pair(i, j));
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        this->board = &board;
        memset(rows, 0, sizeof(rows));
        memset(cols, 0, sizeof(cols));
        memset(boxes, 0, sizeof(boxes));
        emptyCells.clear();
        for (int i = 0; i < 9; ++i)
            for (int j = 0;j < 9; ++j) {
                if (board[i][j] == '.')
                    emptyCells.emplace_back(i, j);
                else {
                    int digit = board[i][j] - '1';
                    int mask = 1 << digit;
                    rows[i] |= mask;
                    cols[j] |= mask;
                    boxes[(i / 3) * 3 + j / 3] |= mask;
                }
            }
        solve();
    }
};