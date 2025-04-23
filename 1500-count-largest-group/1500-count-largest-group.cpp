class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> cnt(37);
        for (int i = 1; i <= n; ++i) {
            int x = i, s = 0;
            while (x) {
                s += x % 10;
                x /= 10;
            }
            ++cnt[s];
        }
        int mx = *max_element(cnt.begin(), cnt.end());
        int res = 0;
        for (int v : cnt)
            if (v == mx)
                ++res;
        return res;
    }
};