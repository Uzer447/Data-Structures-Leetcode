#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), start = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j])
                    start |= 1 << (i * n + j);
        if (!start)
            return 0;
        vector<int> flips;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                int mask = 1 << (i * n + j);
                if (i > 0)
                    mask |= 1 << ((i - 1) * n + j);
                if (i < m - 1)
                    mask |= 1 << ((i + 1) * n + j);
                if (j > 0)
                    mask |= 1 << (i * n + j - 1);
                if (j < n - 1)
                    mask |= 1 << (i * n + j + 1);
                flips.push_back(mask);
            }
        queue<int> q;
        unordered_set<int> seen;
        q.push(start);
        seen.insert(start);
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int state = q.front();
                q.pop();
                if (!state)
                    return steps;
                for (int mask : flips) {
                    int next = state ^ mask;
                    if (!seen.count(next)) {
                        seen.insert(next);
                        q.push(next);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};