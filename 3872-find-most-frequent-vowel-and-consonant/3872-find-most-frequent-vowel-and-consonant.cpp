class Solution {
public:
    int maxFreqSum(string s) {
        int cnt[26] = {0};
        for (char c : s) ++cnt[c - 'a'];
        int mv = 0, mc = 0;
        for (int i = 0; i < 26; ++i) {
            char ch = 'a' + i;
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                mv = max(mv, cnt[i]);
            else
                mc = max(mc, cnt[i]);
        }
        return mv + mc;
    }
};