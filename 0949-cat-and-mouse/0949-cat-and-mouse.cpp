#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        const int MOUSE_WIN = 1, CAT_WIN = 2, DRAW = 0;
        int dp[55][55][2] = {};
        int degree[55][55][2] = {};
        for (int m = 0; m < n; m++) {
            for (int c = 0; c < n; c++) {
                degree[m][c][0] = graph[m].size();
                for (int nei : graph[c]) {
                    if(nei != 0) degree[m][c][1]++;
                }
            }
        }
        queue<array<int,4>> q;
        for (int c = 0; c < n; c++){
            for (int t = 0; t < 2; t++){
                if(dp[0][c][t] == DRAW){
                    dp[0][c][t] = MOUSE_WIN;
                    q.push({0, c, t, MOUSE_WIN});
                }
            }
        }
        for (int m = 1; m < n; m++){
            for (int t = 0; t < 2; t++){
                if(dp[m][m][t] == DRAW){
                    dp[m][m][t] = CAT_WIN;
                    q.push({m, m, t, CAT_WIN});
                }
            }
        }
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            int m = cur[0], c = cur[1], t = cur[2], outcome = cur[3];
            if(t == 0){
                for (int c2 : graph[c]){
                    if(c2 == 0) continue;
                    if(dp[m][c2][1] != DRAW) continue;
                    if(outcome == CAT_WIN){
                        dp[m][c2][1] = CAT_WIN;
                        q.push({m, c2, 1, CAT_WIN});
                    } else {
                        degree[m][c2][1]--;
                        if(degree[m][c2][1] == 0){
                            dp[m][c2][1] = MOUSE_WIN;
                            q.push({m, c2, 1, MOUSE_WIN});
                        }
                    }
                }
            } else {
                for (int m2 : graph[m]){
                    if(dp[m2][c][0] != DRAW) continue;
                    if(outcome == MOUSE_WIN){
                        dp[m2][c][0] = MOUSE_WIN;
                        q.push({m2, c, 0, MOUSE_WIN});
                    } else {
                        degree[m2][c][0]--;
                        if(degree[m2][c][0] == 0){
                            dp[m2][c][0] = CAT_WIN;
                            q.push({m2, c, 0, CAT_WIN});
                        }
                    }
                }
            }
        }
        return dp[1][2][0];
    }
};