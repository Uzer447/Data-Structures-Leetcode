class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> index;
        for(int i = 0; i < n; i++) index[arr[i]] = i;
        vector<vector<int>> dp(n, vector<int>(n, 2));
        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                int needed = arr[i] - arr[j];
                if(needed < arr[j] && index.count(needed)){
                    int k = index[needed];
                    dp[j][i] = dp[k][j] + 1;
                    res = max(res, dp[j][i]);
                }
            }
        }
        return res >= 3 ? res : 0;
    }
};