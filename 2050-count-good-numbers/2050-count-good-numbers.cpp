class Solution {
public:
    long long binpow(long long a, long long b, long long m) {
        a %= m;
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        int MOD = 1e9 + 7;
        if (n == 1)
            return 5;
        long long x=(n+1)/2;
        long long y=n/2;
        long long ans=binpow(5,x,MOD);
        ans*=binpow(4,y,MOD);
        ans=ans%MOD;
        return ans;
    }
};