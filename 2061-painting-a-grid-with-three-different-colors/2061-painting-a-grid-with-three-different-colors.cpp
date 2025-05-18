class Solution {
    static constexpr int MOD = 1'000'000'007;
public:
    int colorTheGrid(int m, int n) {
        if (m > n) swap(m, n);                  
        vector<array<int,5>> state;
        array<int,5> cur{};
        function<void(int,int)> dfs=[&](int r,int prev){
            if (r==m){ state.push_back(cur); return; }
            for (int c=0;c<3;++c){
                if (c==prev) continue;
                cur[r]=c;
                dfs(r+1,c);
            }
        };
        dfs(0,-1);
        int S=state.size();

        vector<vector<int>> tran(S);
        for (int i=0;i<S;++i)
            for (int j=0;j<S;++j){
                bool ok=true;
                for (int r=0;r<m && ok;++r)
                    if (state[i][r]==state[j][r]) ok=false;
                if (ok) tran[i].push_back(j);
            }

        vector<int> dp(S,1),ndp(S);
        for (int col=1;col<n;++col){
            fill(ndp.begin(),ndp.end(),0);
            for (int i=0;i<S;++i){
                if (!dp[i]) continue;
                long long v=dp[i];
                for (int j:tran[i]){
                    ndp[j]+=v;
                    if (ndp[j]>=MOD) ndp[j]-=MOD;
                }
            }
            dp.swap(ndp);
        }

        long long ans=0;
        for (int x:dp){ ans+=x; if (ans>=MOD) ans-=MOD; }
        return (int)ans;
    }
};