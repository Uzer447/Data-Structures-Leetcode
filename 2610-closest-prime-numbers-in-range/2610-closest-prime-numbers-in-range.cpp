#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right + 1, true);
        if(right >= 0) isPrime[0] = false;
        if(right >= 1) isPrime[1] = false;
        for(int i = 2; i * i <= right; i++){
            if(isPrime[i]){
                for(int j = i * i; j <= right; j += i) isPrime[j] = false;
            }
        }
        int prev = -1, best = INT_MAX;
        vector<int> ans = {-1, -1};
        for(int i = max(left, 2); i <= right; i++){
            if(isPrime[i]){
                if(prev != -1 && i - prev < best){
                    best = i - prev;
                    ans[0] = prev;
                    ans[1] = i;
                }
                prev = i;
            }
        }
        return ans;
    }
};