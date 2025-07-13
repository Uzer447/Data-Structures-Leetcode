class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        int m=wordDict.size();
        vector<bool> dp(n+1,false);
        dp[n]=true;
        for(int i=n-1;i>=0;i--)
        {
            for(auto word:wordDict)
            {
                if(i+word.size()<=n)
                {
                    string temp=s.substr(i,word.size());
                cout<<temp<<endl;
                    if(temp==word)
                    {
                        dp[i]=dp[i+word.size()];
                    }
                }
                if(dp[i]) break;
            }
        }
        return dp[0];
    }
};