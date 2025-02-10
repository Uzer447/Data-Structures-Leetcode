class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        
        int m = s1.length();
        int n = s2.length();

        vector<vector<int>>ascii_dp(m+1, vector<int>(n+1, 0)); 

        for(int i = 1; i <= m; i++){
            
            for(int j = 1; j <= n; j++){

                if(s1[i-1] == s2[j-1]) ascii_dp[i][j] = int(s1[i-1]) + ascii_dp[i-1][j-1];

                else{

                    ascii_dp[i][j] = max(ascii_dp[i-1][j], ascii_dp[i][j-1]);
                }
            }
        }

        int largest_ascii_common = ascii_dp[m][n];

        int ascii_s1 = 0;
        for(auto ch: s1) ascii_s1 += int(ch);

        int ascii_s2 = 0;
        for(auto ch: s2) ascii_s2 += int(ch);

        int total_ascii = ascii_s1 + ascii_s2;

        return (total_ascii - (2*largest_ascii_common));
    }
};