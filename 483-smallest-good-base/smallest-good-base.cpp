class Solution {
public:
    typedef unsigned long long ULL;
    string smallestGoodBase(string n_str) {
        ULL n = stoull(n_str);
        int max_m = log2(n)+1;
        for(int m = max_m; m >= 2; m--) {
            long double k_ld = powl((long double)n, 1.0L / (m-1));
            ULL k = (ULL)(k_ld + 0.5L);
            for(ULL candidate = k-1; candidate <= k+1; candidate++) {
                if(candidate <= 1) continue;
                __int128 s = 1, curr = 1;
                for(int i = 1; i < m; i++) {
                    curr *= candidate;
                    if(curr > n) {
                        s = n+1;
                        break;
                    }
                    s += curr;
                    if(s > n) {
                        s = n+1;
                        break;
                    }
                }
                if(s == n) {
                    return to_string(candidate);
                }
            }
        }
        return to_string(n-1);
    }
};