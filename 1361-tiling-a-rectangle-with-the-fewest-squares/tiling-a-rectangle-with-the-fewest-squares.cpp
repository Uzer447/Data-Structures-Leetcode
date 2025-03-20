#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int n, m, best;
    vector<vector<bool>> grid;
    bool canPlace(int x, int y, int k) {
        if(x + k > n || y + k > m) return false;
        for(int i = x; i < x + k; i++)
            for(int j = y; j < y + k; j++)
                if(grid[i][j]) return false;
        return true;
    }
    void setSquare(int x, int y, int k, bool fill) {
        for(int i = x; i < x + k; i++)
            for(int j = y; j < y + k; j++)
                grid[i][j] = fill;
    }
    void dfs(int count) {
        if(count >= best) return;
        int x = -1, y = -1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!grid[i][j]){
                    x = i; y = j;
                    break;
                }
            }
            if(x != -1) break;
        }
        if(x == -1){
            best = min(best, count);
            return;
        }
        int maxSide = min(n - x, m - y);
        for(int k = maxSide; k >= 1; k--){
            if(canPlace(x, y, k)){
                setSquare(x, y, k, true);
                dfs(count + 1);
                setSquare(x, y, k, false);
            }
        }
    }
    int tilingRectangle(int height, int width) {
        n = height;
        m = width;
        best = n * m;
        grid.assign(n, vector<bool>(m, false));
        dfs(0);
        return best;
    }
};