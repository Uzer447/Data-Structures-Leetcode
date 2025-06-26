class Solution {
public:
    int longestSubsequence(string s, int k) {
        long long val = 0, w = 1;
        int res = 0;
        for (int i = (int)s.size() - 1; i >= 0; --i) {
            if (s[i] == '0') {
                ++res;
                if (w <= k) w <<= 1;
            } else if (w <= k && val + w <= k) {
                val += w;
                ++res;
                if (w <= k) w <<= 1;
            }
        }
        return res;
    }
};