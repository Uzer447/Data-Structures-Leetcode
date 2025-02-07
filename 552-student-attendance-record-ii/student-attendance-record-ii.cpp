class Solution {
public:
    int checkRecord(int n) {
        const int MOD = 1000000007;
        vector<int> S(n + 1, 0);
        S[0] = 1;
        if (n >= 1)
            S[1] = 2;
        if (n >= 2)
            S[2] = 4;
        for (int i = 3; i <= n; ++i)
            S[i] = ((long long)S[i - 1] + S[i - 2] + S[i - 3]) % MOD;
        int total_sequences = S[n];
        long long sum_with_one_A = 0;
        for (int i = 0; i < n; ++i)
            sum_with_one_A = (sum_with_one_A + (long long)S[i] * S[n - 1 - i]) % MOD;
        total_sequences = (total_sequences + sum_with_one_A) % MOD;
        return total_sequences;
    }
};