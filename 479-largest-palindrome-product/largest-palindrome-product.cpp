class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;
        int upper = pow(10, n) - 1, lower = pow(10, n - 1);
        for (long long left = upper; left >= lower; --left) {
            string s = to_string(left);
            long long p = stoll(s + string(s.rbegin(), s.rend()));
            for (long long i = upper; i >= lower; --i) {
                if (p / i > upper) break;
                if (p % i == 0) return p % 1337;
            }
        }
        return -1;
    }
};