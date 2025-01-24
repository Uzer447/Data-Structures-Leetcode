class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& ans,vector<vector<int>>& image, int ini, int color) {
        ans[row][col] = color;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        int n = ans.size();
        int m = ans[0].size();
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol]==ini && ans[nrow][ncol]!=color)
            {
                dfs(nrow,ncol,ans,image,ini,color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        vector<vector<int>> ans = image;
        int n = image.size();
        int m = image[0].size();
        int initialColor = ans[sr][sc];
        dfs(sr,sc,ans,image,initialColor,color);
        return ans;
    }
};