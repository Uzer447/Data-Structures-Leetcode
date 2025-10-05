class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& heights,
             set<pair<int, int>>& visit, int prevheight, int n, int m) {
        if (visit.count({row, col}) == 1 || row < 0 || col < 0 || row == n ||
            col == m || heights[row][col] < prevheight) {
            return;
        }
        visit.insert({row, col});
        dfs(row + 1, col, heights, visit, heights[row][col], n, m);
        dfs(row - 1, col, heights, visit, heights[row][col], n, m);
        dfs(row, col + 1, heights, visit, heights[row][col], n, m);
        dfs(row, col - 1, heights, visit, heights[row][col], n, m);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        set<pair<int, int>> pacific;
        set<pair<int, int>> atlantic;
        for (int j = 0; j < m; j++) {
            dfs(0, j, heights, pacific, heights[0][j],n,m);
            dfs(n - 1, j, heights, atlantic, heights[n - 1][j],n,m);
        }
        for(int i=0;i<n;i++)
        {
            dfs(i,0,heights,pacific,heights[i][0],n,m);
            dfs(i,m-1,heights,atlantic,heights[i][m-1],n,m);
        }
        vector<vector<int>> ans;
        for(auto it:pacific)
        {
            if(atlantic.count(it)==1)
            {
                ans.push_back({it.first,it.second});
            }
        }
        return ans;
    }
};