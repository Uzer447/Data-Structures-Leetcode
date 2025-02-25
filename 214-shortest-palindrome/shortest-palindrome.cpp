class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string s_new = s + '#' + rev_s;
        vector<int> lps = computeLPS(s_new);
        int l = lps.back();
        string add = rev_s.substr(0, s.size() - l);
        return add + s;
    }
private:
    vector<int> computeLPS(const string& s) {
        int n = s.size();
        vector<int> lps(n, 0);
        for(int i = 1; i < n; ++i) {
            int len = lps[i - 1];
            while(len > 0 && s[i] != s[len]) {
                len = lps[len - 1];
            }
            if(s[i] == s[len]) {
                ++len;
            }
            lps[i] = len;
        }
        return lps;
    }
};