#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countTriplets(vector<int>& nums) {
        const int max_mask = 1 << 16;
        int full = max_mask - 1;
        vector<int> freq(max_mask, 0);
        for (int num : nums) freq[num]++;
        vector<pair<int, int>> uniq;
        for (int i = 0; i < max_mask; i++)
            if (freq[i]) uniq.push_back({i, freq[i]});
        vector<long long> dp(max_mask, 0);
        for (auto &p : uniq)
            for (auto &q : uniq)
                dp[p.first & q.first] += (long long)p.second * q.second;
        vector<long long> f = dp;
        for (int bit = 0; bit < 16; bit++)
            for (int mask = 0; mask < max_mask; mask++)
                if (mask & (1 << bit)) f[mask] += f[mask ^ (1 << bit)];
        long long ans = 0;
        for (int x = 0; x < max_mask; x++)
            if (freq[x]) {
                int allowed = full ^ x;
                ans += (long long)freq[x] * f[allowed];
            }
        return (int)ans;
    }
};