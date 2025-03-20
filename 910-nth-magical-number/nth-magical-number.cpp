#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        const long long MOD = 1e9 + 7;
        long long g = gcd(a, b);
        long long l = (long long)a / g * b;
        long long low = min(a, b), high = (long long)n * min(a, b);
        while(low < high){
            long long mid = low + (high - low) / 2;
            if(mid / a + mid / b - mid / l < n) low = mid + 1;
            else high = mid;
        }
        return low % MOD;
    }
};