class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vector<vector<int>> a(sz, vector<int>(2));
        for(int i =0;i<sz;i++){
            int z = 0;
            int o = 0;
            for(auto &x : strs[i]){
                z+=(x=='0');
                o+=(x=='1');
            }
            a[i][0] = z;
            a[i][1] = o;
        }
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        int mx = 0;
        for(int i = 0;i<sz;i++){
            for(int j =m;j>=0;j--){
                for(int k=n;k>=0;k--){
                    if(i==0){
                        if(a[i][0]<=j && a[i][1]<=k){
                            dp[j][k] = 1;
                        }
                    }else{
                        if(a[i][0]<=j && a[i][1]<=k){
                            dp[j][k] = max(dp[j][k], dp[j-a[i][0]][k-a[i][1]] + 1);
                        }
                    }
                }
            }
        }
        return dp[m][n];
    }
};