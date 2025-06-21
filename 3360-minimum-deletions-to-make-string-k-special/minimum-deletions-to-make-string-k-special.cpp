class Solution {
public:
    int minimumDeletions(string word, int k) {
        int cnt[26] = {};
        for (char c : word) ++cnt[c - 'a'];
        int mx = 0;
        for (int f : cnt) mx = max(mx, f);
        int best = 0;
        for (int U = 0; U <= mx; ++U) {
            int L = U - k;
            int keep = 0;
            for (int f : cnt) if (f >= L) keep += min(f, U);
            best = max(best, keep);
        }
        return (int)word.size() - best;
    }
};