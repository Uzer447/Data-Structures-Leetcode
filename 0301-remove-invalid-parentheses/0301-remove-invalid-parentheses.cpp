class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int l_rem = 0, r_rem = 0;
        for (char c : s) {
            if (c == '(') {
                l_rem++;
            } else if (c == ')') {
                if (l_rem > 0)
                    l_rem--;
                else
                    r_rem++;
            }
        }
        unordered_set<string> res;
        string expr;
        dfs(s, 0, 0, 0, l_rem, r_rem, expr, res);
        return vector<string>(res.begin(), res.end());
    }
    void dfs(const string &s, int index, int l_count, int r_count, int l_rem, int r_rem, string &expr, unordered_set<string> &res) {
        if (index == s.size()) {
            if (l_rem == 0 && r_rem == 0)
                res.insert(expr);
            return;
        }
        char c = s[index];
        if (c == '(') {
            if (l_rem > 0)
                dfs(s, index + 1, l_count, r_count, l_rem - 1, r_rem, expr, res);
            expr.push_back(c);
            dfs(s, index + 1, l_count + 1, r_count, l_rem, r_rem, expr, res);
            expr.pop_back();
        } else if (c == ')') {
            if (r_rem > 0)
                dfs(s, index + 1, l_count, r_count, l_rem, r_rem - 1, expr, res);
            if (l_count > r_count) {
                expr.push_back(c);
                dfs(s, index + 1, l_count, r_count + 1, l_rem, r_rem, expr, res);
                expr.pop_back();
            }
        } else {
            expr.push_back(c);
            dfs(s, index + 1, l_count, r_count, l_rem, r_rem, expr, res);
            expr.pop_back();
        }
    }
};