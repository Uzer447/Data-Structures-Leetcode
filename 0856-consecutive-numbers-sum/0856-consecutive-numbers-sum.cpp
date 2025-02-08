class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int count = 0;
        int limit = (int)(sqrt(2 * n + 0.25) - 0.5);
        for (int l = 1; l <= limit; ++l) {
            int tmp = n - l * (l - 1) / 2;
            if (tmp <= 0) break;
            if (tmp % l == 0) count++;
        }
        return count;
    }
};