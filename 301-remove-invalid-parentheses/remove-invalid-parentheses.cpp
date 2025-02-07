class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> res;
        int left_rem = 0, right_rem = 0;
        for (char c : s) {
            if (c == '(') {
                left_rem++;
            } else if (c == ')') {
                if (left_rem > 0) {
                    left_rem--;
                } else {
                    right_rem++;
                }
            }
        }
        string expr;
        dfs(s, 0, 0, 0, left_rem, right_rem, expr, res);
        return vector<string>(res.begin(), res.end());
    }
    
    void dfs(string &s, int index, int left_count, int right_count, int left_rem, int right_rem, string &expr, unordered_set<string> &res) {
        if (index == s.size()) {
            if (left_rem == 0 && right_rem == 0)
                res.insert(expr);
            return;
        }
        char c = s[index];
        if (c == '(') {
            if (left_rem > 0)
                dfs(s, index + 1, left_count, right_count, left_rem - 1, right_rem, expr, res);
            expr.push_back(c);
            dfs(s, index + 1, left_count + 1, right_count, left_rem, right_rem, expr, res);
            expr.pop_back();
        } else if (c == ')') {
            if (right_rem > 0)
                dfs(s, index + 1, left_count, right_count, left_rem, right_rem - 1, expr, res);
            if (left_count > right_count) {
                expr.push_back(c);
                dfs(s, index + 1, left_count, right_count + 1, left_rem, right_rem, expr, res);
                expr.pop_back();
            }
        } else {
            expr.push_back(c);
            dfs(s, index + 1, left_count, right_count, left_rem, right_rem, expr, res);
            expr.pop_back();
        }
    }
};