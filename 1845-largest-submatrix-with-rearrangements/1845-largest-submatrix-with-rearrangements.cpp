// 0 0 1      1 0 0
// 1 1 1 =>   1 1 1
// 1 0 1      1 1 0

// col0=2
// col1=1 
// col2=3



class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int ans=0;

        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j])
                {
                    matrix[i][j]+=matrix[i-1][j];
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            vector<int> row=matrix[i];
            sort(row.rbegin(),row.rend());
            for(int j=0;j<n;j++)
            {
                ans=max(ans,row[j]*(j+1));
            }
        }
        return ans;
    }
};