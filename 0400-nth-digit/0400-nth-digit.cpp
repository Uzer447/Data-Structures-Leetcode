class Solution {
public:
    int findNthDigit(int n) {
        int left = 1;
        int right = n;
        int mid;
        long long c;
        while (left <= right) {
            mid = left + (right - left) / 2;
            c = countDig(mid);
            int decider = c + (int)(log(mid) / log(10)) + 1;
            if (c < n && decider >= n)
                break;
            if (c >= n)
                right = mid - 1;
            else if (c < n && decider < n) {
                left = mid + 1;
            }
        }
        string con = to_string(mid);
        return con[n - c - 1] - '0';
    }
    long long countDig(long long n) {
        int d = (int)(log(n) / log(10)) + 1;
        long long sum = 0;
        for (int i = 1; i < d; i++)
            sum += i * (pow(10, i) - pow(10, i - 1));
        sum = sum + d * (n - (long long)(pow(10, d - 1)));
        return sum;
    }
};