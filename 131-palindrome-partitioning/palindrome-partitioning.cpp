class Solution {
public:
    bool isPallindrome(string s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void func(int ind, string s, vector<string>& temp,
              vector<vector<string>>& ans) {
        if (ind == s.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i = ind; i < s.size(); i++) {
            if (isPallindrome(s, ind, i)) {
                temp.push_back(s.substr(ind, i - ind + 1));
                func(i + 1, s, temp, ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        func(0, s, temp, ans);
        return ans;
    }
};