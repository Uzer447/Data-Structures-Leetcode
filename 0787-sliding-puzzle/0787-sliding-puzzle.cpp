class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 3; ++j)
                start += board[i][j] + '0';
        string target = "123450";
        vector<vector<int>> moves = {
            {1, 3}, {0, 2, 4}, {1, 5},
            {0, 4}, {1, 3, 5}, {2, 4}
        };
        unordered_set<string> visited;
        queue<pair<string, int>> q;
        q.push({start, 0});
        visited.insert(start);
        while (!q.empty()) {
            auto [state, step] = q.front(); q.pop();
            if (state == target) return step;
            int zero = state.find('0');
            for (int adj : moves[zero]) {
                string new_state = state;
                swap(new_state[zero], new_state[adj]);
                if (!visited.count(new_state)) {
                    visited.insert(new_state);
                    q.push({new_state, step + 1});
                }
            }
        }
        return -1;
    }
};