MOD = 10**9 + 7
class Solution:
    def countGoodArrays(self, n: int, m: int, k: int) -> int:
        if m == 1:
            if k == n - 1:
                return 1
            else:
                return 0
        else:
            max_n = n  # Maximum value of n needed for factorial precomputations

        # Precompute factorials and inverse factorials
            factorial = [1] * (max_n + 1)
            inverse_factorial = [1] * (max_n + 1)

            for i in range(1, max_n + 1):
                factorial[i] = factorial[i - 1] * i % MOD

            inverse_factorial[max_n] = pow(factorial[max_n], MOD - 2, MOD)
            for i in range(max_n, 0, -1):
                inverse_factorial[i - 1] = inverse_factorial[i] * i % MOD

            def comb(n, k):
                if k < 0 or k > n:
                    return 0
                return factorial[n] * inverse_factorial[k] % MOD * inverse_factorial[n - k] % MOD

            combinations = comb(n - 1, k)
            exponent = n - k - 1
            power = pow(m - 1, exponent, MOD)
            ans = combinations * m % MOD * power % MOD
            return ans