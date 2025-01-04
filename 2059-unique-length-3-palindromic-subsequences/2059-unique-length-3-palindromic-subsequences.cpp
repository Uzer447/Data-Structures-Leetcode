class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int N = s.size();
        vector<int> pre(N), suf(N);
        pre[0] = 1 << (s[0] - 'a');
        for (int i = 1; i < N; ++i)
            pre[i] = pre[i - 1] | (1 << (s[i] - 'a'));
        suf[N - 1] = 1 << (s[N - 1] - 'a');
        for (int i = N - 2; i >= 0; --i)
            suf[i] = suf[i + 1] | (1 << (s[i] - 'a'));
        bool pal[26][26] = {};
        for (int k = 1; k < N - 1; ++k) {
            int x = s[k] - 'a';
            int before = pre[k - 1];
            int after = suf[k + 1];
            for (int c = 0; c < 26; ++c) {
                if ((before & (1 << c)) && (after & (1 << c))) {
                    pal[c][x] = true;
                }
            }
        }
        int count = 0;
        for (int c = 0; c < 26; ++c)
            for (int x = 0; x < 26; ++x)
                if (pal[c][x]) ++count;
        return count;
    }
};