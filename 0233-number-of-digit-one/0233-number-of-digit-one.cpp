class Solution {
public:
    int countDigitOne(int n) {
        long long count = 0, m = 1;
        while (n >= m) {
            long long high = n / (m * 10), curr = (n / m) % 10, low = n % m;
            if (curr == 0) count += high * m;
            else if (curr == 1) count += high * m + low + 1;
            else count += (high + 1) * m;
            m *= 10;
        }
        return count;
    }
};