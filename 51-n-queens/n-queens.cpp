class Solution {
public:
    void func(int col, int n, vector<string>& temp, vector<vector<string>>& ans,
              vector<int>& leftrow, vector<int>& upperDiagonal,
              vector<int>& lowerDiagonal) {
        if (col == n) {
            ans.push_back(temp);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(leftrow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1+col-row]==0)
            {
                temp[row][col]='Q';
                leftrow[row]=1;
                lowerDiagonal[row+col]=1;
                upperDiagonal[n-1+col-row]=1;
                func(col+1,n,temp,ans,leftrow,upperDiagonal,lowerDiagonal);
                temp[row][col]='.';
                leftrow[row]=0;
                lowerDiagonal[row+col]=0;
                upperDiagonal[n-1+col-row]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string row;
        for (int i = 0; i < n; i++)
            row = row + ".";
        vector<string> temp(n,row);
        vector<vector<string>> ans;
        vector <int> leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        func(0,n,temp, ans, leftrow, upperDiagonal, lowerDiagonal);
        return ans;
    }
};