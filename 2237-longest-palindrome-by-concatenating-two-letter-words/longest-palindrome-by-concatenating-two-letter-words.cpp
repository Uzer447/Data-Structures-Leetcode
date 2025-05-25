class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int cnt[26][26] = {};
        for (auto& w : words) ++cnt[w[0]-'a'][w[1]-'a'];
        long long res = 0;
        for (int i = 0; i < 26; ++i)
            for (int j = i + 1; j < 26; ++j)
                res += 4LL * min(cnt[i][j], cnt[j][i]);
        bool mid = false;
        for (int i = 0; i < 26; ++i) {
            res += 4LL * (cnt[i][i] / 2);
            if (cnt[i][i] & 1) mid = true;
        }
        if (mid) res += 2;
        return (int)res;
    }
};