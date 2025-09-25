class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> curr(n+1);
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=i;j++)
            {
                curr[j]=triangle[i][j]+min(curr[j],curr[j+1]);
            }
        }
        return curr[0];
    }
};