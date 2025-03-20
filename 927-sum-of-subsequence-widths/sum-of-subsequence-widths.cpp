#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        const long long mod = 1000000007;
        vector<long long> p2(n, 1);
        for (int i = 1; i < n; i++) 
            p2[i] = (p2[i - 1] * 2) % mod;
        long long res = 0;
        for (int i = 0; i < n; i++) 
            res = (res + nums[i] * ((p2[i] - p2[n - i - 1] + mod) % mod)) % mod;
        return (int)res;
    }
};