class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<bool> dp(n+1,false);
        dp[n]=true;
        for(int i=n-1;i>=0;i--)
        {
            for(auto word:wordDict)
            {
                int m=word.size();
                if(i+m<=n)
                {
                    bool flag=true;
                    for(int j=0;j<m;j++)
                    {
                        if(s[i+j]!=word[j])
                        {
                            flag=false;
                            break;
                        }
                    }
                    if(flag==true)
                    {
                        dp[i]=dp[i+m];
                    }
                }
                else
                {
                    dp[i]=false;
                }
                if(dp[i]==true)
                break;
            }
        }
        return dp[0];
    }
};