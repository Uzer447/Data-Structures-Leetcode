class Solution:
    def kInversePairs(self, n: int, k: int) -> int:
        MOD = 10 ** 9 + 7
        dp_prev = [0] * (k + 1)
        dp_prev[0] = 1

        for num in range(1, n + 1):
            dp_curr = [0] * (k + 1)
            s = [0] * (k + 1)
            s[0] = dp_prev[0]
            for i in range(1, k + 1):
                s[i] = (s[i - 1] + dp_prev[i]) % MOD
            for i in range(k + 1):
                if i >= num:
                    dp_curr[i] = (s[i] - s[i - num] + MOD) % MOD  
                else:
                    dp_curr[i] = s[i]
            dp_prev = dp_curr

        return dp_prev[k] % MOD