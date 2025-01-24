class Solution {
public:
    vector<int> sieve(int n) {
        vector<int> isPrime(n+1, 1);
        isPrime[0] = 0;
        isPrime[1] = 0;
        for (long long i = 2; i*i < n; i++) {
            if (isPrime[i]) {
                for (long long j = i * i; j < n; j += i) {
                    isPrime[j] = 0;
                }
            }
        }
        return isPrime;
    }
    int countPrimes(int n) {
        if(n<=2)return 0;
        vector<int> isPrime=sieve(n);
        int cnt = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i])
                cnt++;
        }
        return cnt;
    }
};