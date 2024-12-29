class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const int mod = 1e9 + 7;
        int L = words[0].size();    // Length of words
        int tlen = target.size();   // Length of target string

        // Step 1: Build frequency matrix
        vector<vector<long long>> freq(L, vector<long long>(26, 0));
        for (const string& word : words) {
            for (int idx = 0; idx < L; ++idx) {
                freq[idx][word[idx] - 'a'] += 1;
            }
        }

        // Step 2: Initialize DP array
        vector<long long> dp(tlen + 1, 0);
        dp[0] = 1;  // Base case: There's 1 way to form an empty string

        // Step 3: Dynamic Programming
        for (int k = 0; k < L; ++k) {
            // Iterate backwards through the target string
            for (int i = tlen - 1; i >= 0; --i) {
                int c = target[i] - 'a';
                long long c_freq = freq[k][c];
                if (c_freq > 0) {
                    dp[i + 1] = (dp[i + 1] + dp[i] * c_freq) % mod;
                }
            }
        }

        // Step 4: Return the result
        return dp[tlen];
    }
};