#include <bits/stdc++.h>
using namespace std;
 
int modExp(long long a, long long b, int mod) {
    long long res = 1;
    a %= mod;
    while(b) {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return (int)res;
}
 
int getPrimeScore(int x, const vector<int>& spf) {
    int cnt = 0, prev = -1;
    while(x > 1) {
        int p = spf[x];
        if(p != prev) { cnt++; prev = p; }
        x /= p;
    }
    return cnt;
}
 
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        const int MOD = 1000000007;
        int n = nums.size(), mx = 0;
        for (int x : nums) mx = max(mx, x);
        vector<int> spf(mx+1);
        for (int i = 0; i <= mx; i++) spf[i] = i;
        for (int i = 2; i * i <= mx; i++) {
            if(spf[i] == i) {
                for (int j = i*i; j <= mx; j += i) {
                    if(spf[j] == j) spf[j] = i;
                }
            }
        }
        vector<int> ps(n);
        for (int i = 0; i < n; i++) ps[i] = getPrimeScore(nums[i], spf);
 
        vector<int> L(n), R(n);
        {
            stack<int> st;
            for (int i = 0; i < n; i++) {
                while (!st.empty() && ps[st.top()] < ps[i])
                    st.pop();
                L[i] = st.empty() ? -1 : st.top();
                st.push(i);
            }
        }
        {
            stack<int> st;
            for (int i = n - 1; i >= 0; i--) {
                while (!st.empty() && ps[st.top()] <= ps[i])
                    st.pop();
                R[i] = st.empty() ? n : st.top();
                st.push(i);
            }
        }
 
        vector<pair<int, long long>> cand;
        for (int i = 0; i < n; i++) {
            long long cnt = (long long)(i - L[i]) * (R[i] - i);
            cand.push_back({nums[i], cnt});
        }
 
        sort(cand.begin(), cand.end(), [](const pair<int, long long>& a, const pair<int, long long>& b) {
            return a.first > b.first;
        });
 
        long long ans = 1, rem = k;
        for (int i = 0; i < cand.size() && rem > 0; i++) {
            long long use = (cand[i].second < rem ? cand[i].second : rem);
            ans = (ans * modExp(cand[i].first, use, MOD)) % MOD;
            rem -= use;
        }
        return (int)ans;
    }
};