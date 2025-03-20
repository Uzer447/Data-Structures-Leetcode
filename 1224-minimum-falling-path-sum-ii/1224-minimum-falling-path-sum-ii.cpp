#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> dp = grid[0];
        for (int i = 1; i < n; i++) {
            int best = INT_MAX, secondBest = INT_MAX, bestIndex = -1;
            for (int j = 0; j < n; j++) {
                if (dp[j] < best) {
                    secondBest = best;
                    best = dp[j];
                    bestIndex = j;
                } else if (dp[j] < secondBest) {
                    secondBest = dp[j];
                }
            }
            vector<int> newdp(n);
            for (int j = 0; j < n; j++) {
                newdp[j] = grid[i][j] + (j == bestIndex ? secondBest : best);
            }
            dp = newdp;
        }
        return *min_element(dp.begin(), dp.end());
    }
};