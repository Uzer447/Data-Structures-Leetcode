class Solution:
    def countPathsWithXorValue(self, grid: List[List[int]], k: int) -> int:
        MOD = 10**9 + 7
        m, n = len(grid), len(grid[0])
        dp = [[[0]*16 for _ in range(n)] for _ in range(m)]
        
        dp[0][0][grid[0][0]] = 1
        
        for i in range(m):
            for j in range(n):
                for x in range(16):
                    current_xor = x ^ grid[i][j]
                    if i > 0:
                        dp[i][j][current_xor] = (dp[i][j][current_xor] + dp[i-1][j][x]) % MOD
                    if j > 0:
                        dp[i][j][current_xor] = (dp[i][j][current_xor] + dp[i][j-1][x]) % MOD
        return dp[m-1][n-1][k]