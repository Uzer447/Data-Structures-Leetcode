class Solution {
public:
    int func(int l,int r,vector<int> &cuts,int n,vector<vector<int>> &dp)
    {
        if(r-l==1)
            return 0;
        if(dp[l][r]!=-1)
            return dp[l][r];
        int ans=INT_MAX;
        for(int i=l+1;i<=r-1;i++)
        {
            ans=min(ans,(cuts[r]-cuts[l])+func(l,i,cuts,n,dp)+func(i,r,cuts,n,dp));
        }
        return dp[l][r]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        int m=cuts.size();
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(m+1,vector<int>(m+1,-1));
        return func(0,cuts.size()-1,cuts,n,dp);
    }
};