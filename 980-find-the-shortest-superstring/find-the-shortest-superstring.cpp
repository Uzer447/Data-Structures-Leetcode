#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> overlap(n, vector<int>(n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(i == j) continue;
                int maxOverlap = min(words[i].size(), words[j].size());
                for (int k = maxOverlap; k > 0; k--) {
                    if(words[i].substr(words[i].size()-k) == words[j].substr(0,k)){
                        overlap[i][j] = k;
                        break;
                    }
                }
            }
        }
        int N = 1 << n;
        vector<vector<string>> dp(N, vector<string>(n, ""));
        for (int i = 0; i < n; i++) {
            dp[1 << i][i] = words[i];
        }
        for (int mask = 0; mask < N; mask++) {
            for (int i = 0; i < n; i++) {
                if(mask & (1 << i)) {
                    for (int j = 0; j < n; j++) {
                        if(mask & (1 << j)) continue;
                        int next_mask = mask | (1 << j);
                        string candidate = dp[mask][i] + words[j].substr(overlap[i][j]);
                        if(dp[next_mask][j] == "" || candidate.size() < dp[next_mask][j].size())
                            dp[next_mask][j] = candidate;
                    }
                }
            }
        }
        string ans = "";
        for (int i = 0; i < n; i++) {
            if(dp[N-1][i] != "" && (ans == "" || dp[N-1][i].size() < ans.size()))
                ans = dp[N-1][i];
        }
        return ans;
    }
};