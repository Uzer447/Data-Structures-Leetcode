class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        double res = 1.0;
        while (N) {
            if (N % 2)
                res *= x;
            x *= x;
            N /= 2;
        }
        return res;
    }
};