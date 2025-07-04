class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int n = operations.size();
        vector<long long> len(n + 1, 1);
        for (int i = 0; i < n; ++i) {
            len[i + 1] = min<long long>(len[i] << 1, (long long)2e18);
        }
        int shift = 0;
        for (int i = n - 1; i >= 0; --i) {
            long long half = len[i];
            if (k > half) {
                k -= half;
                if (operations[i]) shift = (shift + 1) % 26;
            }
        }
        return char('a' + shift);
    }
};