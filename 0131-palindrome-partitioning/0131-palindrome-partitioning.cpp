class Solution {
public:
    bool isPalindrome(string& s, int i, int j) {
        if (i >= j)
            return true;

        if (s[i] == s[j]) {
            return isPalindrome(s, i + 1, j - 1);
        }

        return false;
    }

    void partition(string& s, int start, vector<vector<string>>& ans,
                   vector<string>& par) {
        int n = s.size();
        if (n == start) {
            ans.push_back(par);
        } else {
            for (int i = start; i < n; i++) {
                if (isPalindrome(s, start, i)) {
                    par.push_back(s.substr(start, i - start + 1));
                    partition(s, i + 1, ans, par);
                    par.pop_back();
                }
            }
        }
    }

    vector<vector<string>> partition(string s) {

        int n = s.size();
        vector<vector<string>> ans;
        vector<string> par;

        partition(s, 0, ans, par);

        return ans;
    }
};