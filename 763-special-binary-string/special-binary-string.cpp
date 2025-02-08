class Solution {
public:
    string makeLargestSpecial(string s) {
        return helper(s);
    }
    string helper(string s) {
        vector<string> res;
        int cnt = 0, left = 0;
        for (int i = 0; i < s.size(); ++i) {
            cnt += s[i] == '1' ? 1 : -1;
            if (cnt == 0) {
                string sub = s.substr(left + 1, i - left - 1);
                res.push_back('1' + helper(sub) + '0');
                left = i + 1;
            }
        }
        sort(res.rbegin(), res.rend());
        string ans;
        for (auto& str : res) ans += str;
        return ans;
    }
};