class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int lasta = -1, lastb = -1, lastc = -1;
        int ans = 0;
        int l = 0, r = 0;
        while (r < n) {
            if (s[r] == 'a')
                lasta = r;
            else if (s[r] == 'b')
                lastb = r;
            else
                lastc = r;
            ans += (1 + min(lasta, min(lastb, lastc)));
            r++;
        }
        return ans;
    }
};